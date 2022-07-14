#include "BattleCruser.h"

#include <iostream>

BattleCruser::BattleCruser(const AirShipType type,
                 const int health,
                 const int damage,
                 const int shipId) : TerranAirShip(type, health, damage, shipId) {}

void BattleCruser::dealDamage(std::vector<std::unique_ptr<AirShip>> &enemyFleet) {
    auto& lastShip = enemyFleet.back();

    if (_passedTurns > 1 && _passedTurns % 4 == 0) {
        lastShip->takeDamage(_damage * 5);
        _passedTurns = -1;
    } else {
        lastShip->takeDamage(_damage);
    }

    if (!lastShip->isAlive()) {

        std::cout << "BattleCruser with ID: " << this->getAirShipId() << 
        " killed enemy airship with ID: " << lastShip->getAirShipId() << std::endl;

        enemyFleet.pop_back();
    }
}
