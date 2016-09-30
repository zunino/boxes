/*
 * Texture.hpp
 *
*  Created on: Aug 31, 2014
 *      Author: Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_TEXTURE_HPP
#define SEIDEL_TEXTURE_HPP

#include <SDL.h>

#include "SDLError.hpp"

namespace sdl {

class Texture final {
public:
    Texture(SDL_Renderer* const renderer, const std::string& fileName) throw (SDLError);
    ~Texture();
    SDL_Renderer* renderer() { return sdlRenderer; }
    operator SDL_Texture*() { return sdlTexture; }
private:
    SDL_Renderer* sdlRenderer;
    SDL_Texture* sdlTexture;
};

} /* namespace sdl */

#endif
