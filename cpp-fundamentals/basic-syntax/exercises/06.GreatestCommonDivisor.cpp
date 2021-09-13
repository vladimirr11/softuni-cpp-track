#include <iostream>

int main() {
    int firstNumber = 0;
    int secondNumber = 0;

    std::cin >> firstNumber >> secondNumber;

    int biggerNumber = 0;

    if (firstNumber >= secondNumber) {
        biggerNumber = firstNumber;
    } else {
        biggerNumber = secondNumber;
    }

    for (int i = biggerNumber; i > 0; i--) {
        if (firstNumber % i == 0 && secondNumber % i == 0) {
            std::cout << i << std::endl;
            break;
        }
    }

}