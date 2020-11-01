/*
 * SDL.hpp
 *
*  Created 31 August 2014
*  Last modified 12 June 2019
*
 * Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_SDL_HPP
#define SEIDEL_SDL_HPP

#include <SDL2/SDL.h>

namespace sdl {

    class SDL final {

        public:
            SDL(Uint32 flags);
            SDL(const SDL&) = delete;
            ~SDL();

    };

}

#endif
