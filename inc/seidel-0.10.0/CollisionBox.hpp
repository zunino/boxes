/**
 * CollisionBox.hpp
 *
 * Bounding box used for 2D collision detection.
 *
 * Created 4 June 2019
 * Last modified 4 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#ifndef AZ_COLLISION_BOX_HPP
#define AZ_COLLISION_BOX_HPP

#include "Vector.hpp"

namespace sdl {

    struct CollisionBox {
        sdl::Vector p1;
        sdl::Vector p2;
        bool collidesWith(const CollisionBox& rhs) const;
    };

}

#endif
