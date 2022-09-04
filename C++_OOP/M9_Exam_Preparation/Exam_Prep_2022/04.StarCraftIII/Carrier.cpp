#include <iostream>

#include "Carrier.h"

Carrier::Carrier(const AirShipType type, const int health, const int damage,
                 const int maxShield, const int shieldRegenerateRate, const int shipId)
    : ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId),
    _activeInterceptors(MAX_INTERCEPTORS) {}

void Carrier::takeDamage(const int damage) {
    ProtossAirShip::takeDamage(damage);
    if (_currHealth < _maxHealth) {
        _activeInterceptors = DAMAGED_STATUS_INTERCEPTORS;
    } else {
        _activeInterceptors = MAX_INTERCEPTORS;
    }
}

void Carrier::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
    for (int i = 0; i < _activeInterceptors; ++i) {
        if (!enemyFleet.empty()) {
            std::unique_ptr<AirShip>& last_ship = enemyFleet.back();
            last_ship->takeDamage(_damage);
            if (last_ship->getCurrHealth() <= 0) {
                std::cout << "Carrier with ID: " << _shipId << " killed enemy airship with ID: " 
                << last_ship->getAirShipId() << std::endl;
                enemyFleet.pop_back();
            }
        }
    }
}
