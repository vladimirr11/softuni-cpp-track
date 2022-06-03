#include <iostream>
#include <array>
#include <cctype>
#include <cmath>

const int maxSize = 1000;

std::array<char, maxSize> readInput(int& arraySize) {
    char c = ' ';
    std::array<char, maxSize> array {};

    while (true) {
        std::cin >> c;

        if (c == '.') {
            break;
        }

        array[arraySize] = c;
        arraySize++;
    }
    
    return array;
}

int getIntFromChar(char c) {
    return c - '0';
}

void appendDigitToNumber(char digit, int& number) {
    number *= 10;
    number += getIntFromChar(digit);
}

int main() {
    int arrSize = 0;

    std::array<char, maxSize> arr = readInput(arrSize);

    int number = 0;
    for (int i = 0; i < arrSize; i++) {
        if (isdigit(arr[i])) {
            appendDigitToNumber(arr[i], number);
        }
    }

    std::cout << sqrt(number) << std::endl;

    return 0;
}
