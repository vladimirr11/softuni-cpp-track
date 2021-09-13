#include <iostream>

int main() {
    int numOne;
    int numTwo;
    int numThree;

    std::cin >> numOne >> numTwo >> numThree;

    int result = numOne * numTwo * numThree;

    if (result >= 0) {
        std::cout << "+" << std::endl;
    } else {
        std::cout << "-" << std::endl;
    }

}