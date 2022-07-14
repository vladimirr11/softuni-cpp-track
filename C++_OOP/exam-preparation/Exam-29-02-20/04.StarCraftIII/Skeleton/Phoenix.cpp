#include "Phoenix.h"
#include <iostream>

Phoenix::Phoenix(const AirShipType type,
            const int health,
            const int damage,
            const int maxShield,
            const int shieldRegenerateRate,
            const int shipId) :
    ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId) {}

void Phoenix::dealDamage(std::vector<std::unique_ptr<AirShip>> &enemyFleet) {
    auto& lastShip = enemyFleet.back();
    lastShip->takeDamage(_damage);

    if (lastShip->getCurrHealth() <= 0) {
         std::cout << "Phoenix with ID: " << this->getAirShipId() << 
        " killed enemy airship with ID: " << enemyFleet.back()->getAirShipId() << std::endl;

        enemyFleet.pop_back();
    }
}
