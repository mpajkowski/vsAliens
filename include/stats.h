//
// Created by marcin on 2/1/17.
//

#pragma once

#include <ctime>

namespace stats {
    namespace game {
        extern bool isActive;
        extern int score;
        extern int lives;
    }
    namespace enemy {
        extern time_t lastSpawnTime;
        extern int enemyCounter_test;
    }
}
