#include "AutomaticCar.h"

AutomaticCar::AutomaticCar(int maxSpeed, int fuel) : Car(maxSpeed, fuel) {}

void AutomaticCar::increaseSpeed(int speedIncrease, int fuelConsumtion) {
    _currSpeed += speedIncrease;

    if (_currSpeed > _maxSpeed) {
        _currSpeed = _maxSpeed;
    }

    _fuel -= fuelConsumtion;
    if (_fuel < 0) {
        _currSpeed = 0;
        _fuel = 0;
    }
}

void AutomaticCar::decreaseSpeed(int speedDecrease) {
    _currSpeed -= (speedDecrease * 2);

    if (_currSpeed < 0) {
        _currSpeed = 0;
    }
}
