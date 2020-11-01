/*
 * Window.hpp
 *
 * Created 31 August 2014
 * Last modified 12 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_WINDOW_HPP
#define SEIDEL_WINDOW_HPP

#include <SDL2/SDL.h>

namespace sdl {

    class Window {

        public:
            Window(const char* title, int w, int h);
            Window(const char* title, int w, int h, Uint32 flags);
            Window(const char* title, int x, int y, int w, int h, Uint32 flags);
            Window(const Window&) = delete;
            virtual ~Window();

            SDL_Renderer* renderer();
            SDL_Renderer* renderer(Uint32 flags);

            void clear(const SDL_Color& color = {0, 0, 0, 255});

        private:
            SDL_Window* sdlWindow;
            SDL_Renderer* sdlRenderer;

    };

} /* namespace sdl */

#endif
