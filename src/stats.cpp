#include "../include/stats.h"

namespace stats {
    namespace game {
        bool isActive = false;
        int score = 0;
        int lives = 1;
    }
    namespace enemy {
        sf::Vector2f lastPos;
        int fragCounter = 0;
    }
}
