/*
 * Text.hpp
 *
 * Created 12 June 2019
 * Last modified 23 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_TEXT_HPP
#define SEIDEL_TEXT_HPP

#include <string_view>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace sdl {

    struct Text;

    struct Font final {
        Font(std::string_view name, int size);
        Font(const Font& font) = delete;
        ~Font();
        operator TTF_Font*() const;
    private:
        TTF_Font* font;
    };

    struct Writer {
        friend struct Text;
        void write(std::string_view text, int x, int y) const;
    private:
        Writer(SDL_Renderer* renderer, Font& font, const SDL_Color& color);
        SDL_Renderer* renderer;
        Font& font;
        SDL_Color color;
    };

    struct Text final {
        Text(SDL_Renderer* renderer);
        ~Text();
        Writer writer(Font& font, const SDL_Color& color) const;
    private:
        SDL_Renderer* renderer;
    };

}

#endif
