#include <iostream>

int main() {
    int n = 0;
    int minNumber = INT16_MAX;
    int maxNumber = INT16_MIN;

    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        int currentNumber = 0;
        std::cin >> currentNumber;

        if (currentNumber < minNumber) {
            minNumber = currentNumber;
        } 

        if (currentNumber > maxNumber) {
            maxNumber = currentNumber;
        }
    }

    std::cout << minNumber << ' ' << maxNumber << std::endl;

}