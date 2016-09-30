/*
 * Window.hpp
 *
*  Created on: Aug 31, 2014
 *      Author: Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_WINDOW_HPP
#define SEIDEL_WINDOW_HPP

#include <SDL.h>

#include "SDLError.hpp"

namespace sdl {

    class Window {

        public:
            Window(const char* title, int w, int h) throw (SDLError);
            Window(const char* title, int w, int h, Uint32 flags) throw (SDLError);
            Window(const char* title, int x, int y, int w, int h, Uint32 flags) throw (SDLError);
            virtual ~Window();

            SDL_Renderer* renderer() throw (SDLError);
            SDL_Renderer* renderer(Uint32 flags) throw (SDLError);

        private:
            SDL_Window* sdlWindow;
            SDL_Renderer* sdlRenderer;

    };

} /* namespace sdl */

#endif
