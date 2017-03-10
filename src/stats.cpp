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

    namespace bullet {
        float speed = settings::bullet::speed;
        int maxBullets = settings::bullet::maxBullets;
        int bulletsLeft = stats::bullet::maxBullets;
    }
}
