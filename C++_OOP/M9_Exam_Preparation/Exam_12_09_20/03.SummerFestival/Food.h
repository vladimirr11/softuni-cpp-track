#ifndef FOOD_H
#define FOOD_H

#include <string>
#include <vector>
#include <iostream>

#include "Order.h"

class Food {
public:
    Food();

    void cook(std::string type, std::string size, double price);

    void sell(int index);

    void copy(int indexFrom, int indexTo);

private:
    std::vector<Order> orders;
};

#endif // !FOOD_H
