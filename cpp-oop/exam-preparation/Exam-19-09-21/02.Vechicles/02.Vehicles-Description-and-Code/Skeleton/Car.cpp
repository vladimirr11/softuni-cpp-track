#include "Car.h"

Car::Car(int maxSpeed, int fuel) : _maxSpeed(maxSpeed), _currSpeed(0), _fuel(fuel), _distanceTraveled(0) {}

void Car::increaseSpeed(int speedIncrease, int fuelConsumtion) {
    _currSpeed += speedIncrease;
    _fuel -= fuelConsumtion;
}

void Car::decreaseSpeed(int speedDecrease) {
    _currSpeed -= speedDecrease;
}

int Car::getFuel() const {
    return _fuel;
}

int Car::getDistance() const {
    return _distanceTraveled;
}

int Car::getCurrSpeed() const {
    return _currSpeed;
}

int Car::setCurrDistance(int speed) {
    _distanceTraveled += speed;

    return _distanceTraveled;
}
