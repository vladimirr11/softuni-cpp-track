#include <iostream>

int main() {
    int numOne;
    int numTwo;

    std::cin >> numOne >> numTwo;

    if (numTwo > numOne) {
        std::cout << numOne << " " << numTwo << std::endl;
    } else {
        std::cout << numTwo << " " << numOne << std::endl;
    }

}