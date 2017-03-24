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
extern const float MOVE_SPEED;
}

namespace enemy {
extern const float MOVE_SPEED;
}

namespace textures {
extern sf::Font font;
extern sf::Texture shipTexture;
extern sf::Texture enemyTexture;
}

namespace bullet {
extern float speed;
extern int maxBullets;
}
}
