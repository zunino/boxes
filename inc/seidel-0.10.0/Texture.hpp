/*
 * Texture.hpp
 *
 * Created 31 August 2014
 * Last modified 12 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_TEXTURE_HPP
#define SEIDEL_TEXTURE_HPP

#include <string>
#include <array>

#include <SDL2/SDL.h>

namespace sdl {

    class Texture final {

        public:
            static const int MAIN_COLORS_SIZE = 10;

        public:
            static std::array<SDL_Color, MAIN_COLORS_SIZE> extractMainColors(
                    SDL_Surface* const surface);

        public:
            Texture(SDL_Renderer* const renderer, const std::string& fileName);
            Texture(SDL_Renderer* const renderer, SDL_Surface* const surface);
            Texture(const Texture&) = delete;
            ~Texture();
            SDL_Renderer* renderer() { return sdlRenderer; }
            operator SDL_Texture*() { return sdlTexture; }

        private:
            SDL_Texture* createTexture(SDL_Renderer* const renderer,
                    SDL_Surface* const surface);

        private:
            SDL_Renderer* sdlRenderer;
            SDL_Texture* sdlTexture;

    };

}

#endif
