/**
 * Random.hpp
 * 
 * Random number generation utilities. Interval parameters are inclusive.
 *
 * Created 16 May 2019
*  Last modified 4 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_RANDOM_HPP
#define SEIDEL_RANDOM_HPP

#include <random>

namespace sdl {

    int random(int from, int to);
    int random(int to);              // from 0 to 'to'

    float random(float from, float to);
    float random(float to);

}

#endif

