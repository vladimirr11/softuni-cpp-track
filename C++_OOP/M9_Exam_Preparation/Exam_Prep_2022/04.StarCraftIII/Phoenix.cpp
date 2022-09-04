#include <iostream>

#include "Phoenix.h"

Phoenix::Phoenix(const AirShipType type, const int health, const int damage,
                 const int maxShield, const int shieldRegenerateRate, const int shipId)
    : ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId) {}

void Phoenix::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
    if (!enemyFleet.empty()) {
        std::unique_ptr<AirShip>& last_ship = enemyFleet.back();
        last_ship->takeDamage(_damage);
        if (last_ship->getCurrHealth() <= 0) {
            std::cout << "Phoenix with ID: " << _shipId << " killed enemy airship with ID: " 
            << last_ship->getAirShipId() << std::endl;
            enemyFleet.pop_back();
        }
    }
}
