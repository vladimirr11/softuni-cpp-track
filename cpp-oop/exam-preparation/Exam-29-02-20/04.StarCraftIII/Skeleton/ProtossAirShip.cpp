#include "ProtossAirShip.h"
#include <math.h>

ProtossAirShip::ProtossAirShip(const AirShipType type,
                   const int health,
                   const int damage,
                   const int maxShield,
                   const int shieldRegenerateRate,
                   const int shipId) : 
    AirShip(type, health, damage, shipId), _maxShield(maxShield), 
    _currShield(maxShield), _shieldRegenerateRate(shieldRegenerateRate) {}


void ProtossAirShip::takeDamage(const int damage) {
    this->_currShield -= damage;
    
    if (this->_currShield < 0) {
        this->_currHealth -= std::abs(0 - _currShield);
        _currShield = 0;
    }
}

void ProtossAirShip::finishTurn() {
    if (_airShipType == AirShipType::PHOENIX) {
        _currShield += _shieldRegenerateRate;
        if (_currShield > _maxShield) {
            _currShield = _maxShield;
        }

    } else if (_airShipType == AirShipType::CARRIER) {
        _currShield += 40;
        if (_currShield > _maxShield) {
            _currShield = _maxShield;
        }
    }
}