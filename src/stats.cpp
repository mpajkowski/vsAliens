#include "../include/stats.h"

namespace stats {
    namespace game {
        bool isActive = false;
        int score = 0;
        int lives = 1;
    }
    namespace enemy {
        time_t lastSpawnTime;
        int enemyCounter_test;
    }
}
