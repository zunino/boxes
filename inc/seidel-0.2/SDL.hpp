/*
 * SDL.hpp
 *
*  Created on: Aug 31, 2014
 *      Author: Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_SDL_HPP
#define SEIDEL_SDL_HPP

#include <SDL.h>

#include "SDLError.hpp"

namespace sdl {

class SDL final {
public:
    SDL(Uint32 flags) throw (SDLError);
    ~SDL();
};

} /* namespace sdl */

#endif
