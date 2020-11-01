/**
 * Utils.hpp
 *
 * General utilities.
 *
 * Created 8 June 2019
 * Last modified 12 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_UTILS_HPP
#define SEIDEL_UTILS_HPP

#include <iostream>
#include <iterator>

#include <SDL2/SDL_pixels.h>

#include "Random.hpp"

namespace sdl {

    template <typename T>
    const T& clamp(const T& value, const T& min, const T& max) {
        if (value < min) {
            return min;
        } else if (value > max) {
            return max;
        } else {
            return value;
        }
    }

    // Template template parameter
    template <template <typename...> typename Coll, typename E>
    const E& randomElement(const Coll<E>& collection) {
        int size = collection.size();
        if (size > 0) --size;
        int offset = random(size);
        auto iter = std::begin(collection);
        std::advance(iter, offset);
        return *iter;
    }

}

std::ostream& operator<<(std::ostream& os, const SDL_Color& c);

#endif

