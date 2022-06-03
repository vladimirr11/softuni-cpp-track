#include <iostream>
#include <cmath>

void selectClosestPoint(const float& numOne, const float& numTwo,  const float& numThree, const float& numFour) {
    float pointOne = pow(numOne, 2) + pow(numTwo, 2);
    float pointTwo = pow(numThree, 2) + pow(numFour, 2);

    if (pointOne <= pointTwo) {
        std::cout << "(" << numOne << ", " << numTwo << ")" << std::endl;
    } else {
        std::cout << "(" << numThree << ", " << numFour << ")" << std::endl;
    }
}

int main() {
    float numberOne;
    float numberTwo;
    float numberThree;
    float numberFour;

    std::cin >> numberOne >> numberTwo >> numberThree >> numberFour;

    selectClosestPoint(numberOne, numberTwo, numberThree, numberFour);

    return 0;
}
