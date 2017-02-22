//
// Created by marcin on 2/1/17.
//

#pragma once

#include "shared.h"

namespace settings {
    namespace window {
        extern const int WIDTH;
        extern const int HEIGHT;
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

    namespace fonts {
        extern sf::Font font;
    }

    namespace bullet {
        extern double speed;
        }
}
