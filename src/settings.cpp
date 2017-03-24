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
    const float MOVE_SPEED = 300;
}

namespace enemy {
    const float MOVE_SPEED = 100;
}

namespace textures {
    sf::Texture shipTexture;
    sf::Texture enemyTexture;
}

namespace bullet {
    float speed = 500;
    int maxBullets = 4;
}
}
