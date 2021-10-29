#include "ManualCar.h"

#include <cstddef>

ManualCar::ManualCar(const std::vector<int> &shiftSpeeds, int maxSpeed, int fuel) : 
        Car(maxSpeed, fuel), _shiftSpeeds(shiftSpeeds) {}

void ManualCar::increaseSpeed(int speedIncrease, int fuelConsumtion) {
    _currSpeed += speedIncrease;

    bool isDouble = false;
    for (int i = 0; i < _shiftSpeeds.size(); i++) {
        if (_currSpeed >= _shiftSpeeds[i]) {
            isDouble = true;
        }
    }

    if (_currSpeed > _maxSpeed) {
        _currSpeed = _maxSpeed;
    }

    if (!isDouble) {
        _fuel -= fuelConsumtion;
            
        if (_fuel < 0) {
            _fuel = 0;
        }

    } else {
        _fuel -= fuelConsumtion * 2;
        
        if (_fuel <= 0) {
            _currSpeed = 0;
            _fuel = 0;
        }
    }

}

size_t ManualCar::findShiftIdx() const {
    return _currShiftIdx;
}

void ManualCar::decreaseSpeed(int speedDecrease) {
    _currSpeed -= speedDecrease;
    if (_currSpeed < 0) {
        _currSpeed = 0;
    }
}
