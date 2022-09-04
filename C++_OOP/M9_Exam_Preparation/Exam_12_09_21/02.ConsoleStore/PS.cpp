#include "PS.h"

PS::PS(int price, int quality, int generatio) 
    : Console(price, quality), _generation(generatio) {}

int PS::getGeneration() const {
    return _generation;
}
