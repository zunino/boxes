/*
 * Clock.hpp
 *
*  Created on: Aug 31, 2014
 *      Author: Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_CLOCK_HPP
#define SEIDEL_CLOCK_HPP

#include <SDL.h>

namespace sdl {

constexpr int operator"" _fps(unsigned long long fps) { return static_cast<int>(fps); }

class Clock final {
public:
    Clock(int fps);
    Clock(const Clock&) = delete;
    Uint32 elapsedMilliseconds() const;
    float elapsedSeconds() const { return elapsedMilliseconds() / 1000.0f; }
    float averageFPS() const { return avgFPS; }
    void startFrame();
    void endFrame();
    float remainingFrameTime() const;
    float frameDuration() const { return singleFrameDuration; }
private:
    static const int NO_OF_FRAMES_FOR_FPS_AVERAGE = 120;
private:
    const float singleFrameDuration;
    Uint32 currentTicks;
    Uint32 elapsedTicks;
    Uint32 accumulatedTicks;
    int frameCountForAvg;
    float avgFPS;
};

} /* namespace sdl */

#endif
