#include "House.h"

House::House(int width, int length) : Building(width, length) {
    House::print();
    std::cout << "| Constructor is called" << std::endl;
}

void House::print() {
    std::cout << "Building type: House, measurements: " << 
    Building::getWidth() << " x " << Building::getLength() << std::endl;
}

House::~House() {
    House::print();
    std::cout << "| Destructor is called" << std::endl;
}
