//
// Created by marcin on 2/1/17.
//

#pragma once
#include "shared.h"
#include <ctime>

namespace stats {
    namespace game {
        extern bool isActive;
        extern int score;
        extern int lives;
    }
    namespace enemy {
        extern sf::Vector2f lastPos;
        extern int fragCounter;
    }

    namespace bullet {
        extern double speed;
    }
}
