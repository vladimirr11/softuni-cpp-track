#ifndef CAR_H
#define CAR_H

class Car {
public:
    Car(int maxSpeed, int fuel);

    void virtual increaseSpeed(int speedIncrease, int fuelConsumtion);

    void virtual decreaseSpeed(int speedDecrease);

    int getFuel() const;

    int getDistance() const;

    int getCurrSpeed() const;

    int setCurrDistance(int speed);

protected:
    int _maxSpeed = 0;
    int _currSpeed;
    int _fuel = 0;
    int _distanceTraveled;
};

#endif // !CAR_H
