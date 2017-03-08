//
// Created by marcin on 2/1/17.
//

#include "../include/settings.h"

namespace settings {
    namespace window {
        const unsigned int WIDTH = 1000;
        const unsigned int HEIGHT = 700;
    }

    namespace ship {
        const int MOVE_SPEED = 300;
    }

    namespace enemy {
        const int MOVE_SPEED = 100;
    }

    namespace textures {
        sf::Font font;
        sf::Texture shipTexture;
        sf::Texture enemyTexture;
    }

    namespace bullet {
        double speed = 500;
        int maxBullets = 4;
    }
}
