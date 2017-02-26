//
// Created by marcin on 2/1/17.
//

#pragma once

#include "shared.h"

namespace settings {
    namespace window {
        extern const unsigned int WIDTH;
        extern const unsigned int HEIGHT;
    }

    namespace ship {
        extern const int MOVE_SPEED;
    }

    namespace enemy {
        extern const int MOVE_SPEED;
    }

    namespace textures {
        extern sf::Texture shipTexture;
        extern sf::Texture enemyTexture;
    }

    namespace bullet {
        extern double speed;
        extern int maxBullets;
        }
}
