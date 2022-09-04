#include "RaceTrack.h"

#include "ManualCar.h"
#include "AutomaticCar.h"

#include <iostream>

bool RaceTrack::isRaceRunning() const {
    for (const auto& car : _cars) {
        if (car->getFuel() == 0) {
            return false;
        }
    }
    return true;
}

void RaceTrack::printWinner() {
    if (_cars[0]->getFuel() == 0) {
        std::cout << "Car with index: 1 won!" << std::endl;
        return;
    } else if (_cars[1]->getFuel() == 0) {
        std::cout << "Car with index: 0 won!" << std::endl;
        return;
    } else if (_cars[0]->getFuel() > 0 && _cars[1]->getFuel() > 0) {
        if (_cars[0]->getDistance() == _cars[1]->getDistance()) {
            std::cout << "No winner" << std::endl;
        } else if (_cars[0]->getDistance() > _cars[1]->getDistance()) {
            std::cout << "Car with index 0: won!" << std::endl;
        } else if (_cars[0]->getDistance() < _cars[1]->getDistance()) {
            std::cout << "Car with index 1: won!" << std::endl;
        }
    } 
}

void RaceTrack::createManualCar(const std::vector<int>& shifts, int maxSpeed, int startFuel) {
    _cars.emplace_back(new ManualCar(shifts, maxSpeed, startFuel));
}

void RaceTrack::createAutomaticCar(int maxSpeed, int startFuel) {
    _cars.emplace_back(new AutomaticCar(maxSpeed, startFuel));
}

void RaceTrack::increaseSpeed(int speedIncrease, int fuelConsumtion) {
    _cars[0]->increaseSpeed(speedIncrease, fuelConsumtion);
    _cars[1]->increaseSpeed(speedIncrease, fuelConsumtion);
}

void RaceTrack::decreaseSpeed(int speedDecrease) {
    _cars[0]->decreaseSpeed(speedDecrease);
    _cars[1]->decreaseSpeed(speedDecrease);
}

void RaceTrack::advance() {
    _cars[0]->setCurrDistance(_cars[0]->getCurrSpeed());
    _cars[1]->setCurrDistance(_cars[1]->getCurrSpeed());
}

void RaceTrack::printInfo() const {
    for (int i = 0; i < _cars.size(); i++) {
        std::cout << "Car with index: " << i << " has totalDistance: " << _cars[i]->getDistance() 
        << ", is running with " << _cars[i]->getCurrSpeed() << " speed, has " 
        << _cars[i]->getFuel() << " fuel left" << std::endl;
    }
}
