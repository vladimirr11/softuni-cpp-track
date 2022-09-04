#include <iostream>

#include "BattleCruser.h"

BattleCruser::BattleCruser(const AirShipType type, const int health, const int damage, const int shipId)
    : TerranAirShip(type, health, damage, shipId) {}

void BattleCruser::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
    if (!enemyFleet.empty()) {
        std::unique_ptr<AirShip>& last_ship = enemyFleet.back();
        if (_passedTurns % 4 == 0 && _passedTurns > 1) {
            last_ship->takeDamage(_damage * 5);
            if (last_ship->getCurrHealth() <= 0) {
                std::cout << "BattleCruser with ID: " << _shipId << " killed enemy airship with ID: " 
                << last_ship->getAirShipId() << std::endl;
                enemyFleet.pop_back();
            }
            _passedTurns = -1;
            
        } else {
            last_ship->takeDamage(_damage);
            if (last_ship->getCurrHealth() <= 0) {
                std::cout << "BattleCruser with ID: " << _shipId << " killed enemy airship with ID: " 
                << last_ship->getAirShipId() << std::endl;
                enemyFleet.pop_back();
            }
        }
    }
}
