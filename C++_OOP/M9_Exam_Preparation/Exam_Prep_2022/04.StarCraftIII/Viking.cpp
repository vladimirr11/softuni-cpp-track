#include <iostream>

#include "Viking.h"

Viking::Viking(const AirShipType type, const int health, const int baseDamage, const int shipId) 
    : TerranAirShip(type, health, baseDamage, shipId) {}

void Viking::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
    if (!enemyFleet.empty()) {
        std::unique_ptr<AirShip>& last_ship = enemyFleet.back();
        if (last_ship->getAirShipType() == AirShipType::PHOENIX) {
            last_ship->takeDamage(_damage * 2);
            if (last_ship->getCurrHealth() <= 0) {
                std::cout << "Viking with ID: " << _shipId << " killed enemy airship with ID: " 
                << last_ship->getAirShipId() << std::endl;
                enemyFleet.pop_back();
            }
        } else { 
            last_ship->takeDamage(_damage);
            if (last_ship->getCurrHealth() <= 0) {
                std::cout << "Viking with ID: " << _shipId << " killed enemy airship with ID: " 
                << last_ship->getAirShipId() << std::endl;
                enemyFleet.pop_back();
            }
        }
    }
}
