#include "Palace.h"

Palace::Palace(int width, int length) : Building(width, length) {
    Palace::print();
    std::cout << "| Constructor is called" << std::endl;
}

void Palace::print() {
    std::cout << "Building type: Palace, measurements: " << 
    Building::getWidth() << " x " << Building::getLength() << std::endl;
}

Palace::~Palace() {
    Palace::print();
    std::cout << "| Destructor is called" << std::endl;
}
