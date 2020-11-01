/*
 * Sprite.hpp
 *
 * Created 31 August 2014
 * Last modified 12 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_SPRITE_HPP
#define SEIDEL_SPRITE_HPP

#include <map>
#include <string>

#include <SDL2/SDL.h>

namespace sdl {

    class Texture;

    /**
    * A sprite is a 2D graphical representation of a game entity and its associated animations.
    * Each sprite can have one or more animations, each composed of one or more frames.
    */
    class Sprite {

        struct Animation {
            enum class Type {
                CYCLIC, // f1->f2->f3->f1->f2->f3->f1...
                BOUNCE, // f1->f2->f3->f2->f1->f2->f3...
                ONCE    // f1->f2->f3
            };
            static const std::string DEFAULT_ANIMATION_NAME;
            Animation(std::string name, int tx, int ty, int fw, int fh, int fcount,
                    float fps, Type type = Type::CYCLIC, int initialFrame = 0);
            void changeType(Type type);
            void update(float elapsedTime, SDL_Rect& src);
            std::string name;
            int tx, ty;
            int fw, fh;
            int fcount;
            float frameDuration; // duration of each frame, in milliseconds
            float accElapsedTime;
            Type type;
            int frame;
            int delta; // -1 or +1: controls direction of animation increments, depending on the animation type
        };

        public:
            // texture: contains the image where the sprite's animation frames are read from
            // tx, ty: coordinates of the first frame of the sprite's default animation
            // fw, fh: dimensions of each animation frame (assumed to be the same for all frames)
            // fcount: number of frames in the default animation
            // fps:
            // initialFrame: the frame from the which the animation should start
            Sprite(Texture& texture, int tx, int ty, int fw, int fh, int fcount, float fps);
            Sprite(Texture& texture, int tx, int ty, int fw, int fh, int fcount, float fps, int initialFrame);
            virtual ~Sprite();
            void changeAnimation(const std::string& name, int initialFrame = 0);
            void addAnimation(const std::string& name, int tx, int ty, int fw, int fh, int fcount,
                            float fps, Animation::Type type = Animation::Type::CYCLIC);
            void update(float elapsedTime, float x, float y);
            void draw() const;
            void zoom(float z) { zoomFactor = z; }

        private:
            void updateRects();

        private:
            Texture& texture;
            std::map<std::string, Animation> animations;
            std::string animationName;
            float zoomFactor;
            SDL_Rect src;
            SDL_Rect dst;

    };

} /* namespace sdl */

#endif
