//
// Created by marcin on 2/1/17.
//

#ifndef VSALIENS_STATS_H
#define VSALIENS_STATS_H

#include <ctime>

namespace stats {
    namespace game {
        bool isActive = false;
    }
    namespace enemy {
        time_t lastSpawnTime;
        int enemyCounter_test;
    }
}
#endif //VSALIENS_STATS_H
