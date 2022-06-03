#include <iostream>
#include <cmath>

const int firstDigitIdx = 0;
const int secondDigitIdx = 1;
const int thitdDigitIdx = 2;
const int fourthDigitIdx = 3;

void printDigit(int digit) {
    switch(digit) {
        case 1: std::cout << "one"; 
        break;
        case 2: std::cout << "two"; 
        break;
        case 3: std::cout << "three"; 
        break;
        case 4: std::cout << "four"; 
        break;
        case 5: std::cout << "five"; 
        break;
        case 6: std::cout << "six"; 
        break;
        case 7: std::cout << "seven"; 
        break;
        case 8: std::cout << "eight"; 
        break;
        case 9: std::cout << "nine"; 
        break;
    }
}

void printTeenNumbers(int number) {
    switch(number) {
        case 10: std::cout << "ten";
        break;
        case 11: std::cout << "eleven";
        break;
        case 12: std::cout << "twelve";
        break;
        case 13: std::cout << "thirteen";
        break;
        case 14: std::cout << "fourteen";
        break;
        case 15: std::cout << "fifteen";
        break;
        case 16: std::cout << "sixteen";
        break;
        case 17: std::cout << "seventeen";
        break;
        case 18: std::cout << "eighteen";
        break;
        case 19: std::cout << "nineteen";
        break;
    }
}

void printTens(int number) {
    switch(number) {
        case 2: std::cout << "twenty";
        break;
        case 3: std::cout << "thirty";
        break;
        case 4: std::cout << "fourty";
        break;
        case 5: std::cout << "fifty";
        break;
        case 6: std::cout << "sixty";
        break;
        case 7: std::cout << "seventy";
        break;
        case 8: std::cout << "eighty";
        break;
        case 9: std::cout << "ninety";
        break;
    }
}

int getDigitFromIndex(int number, int index) {
    const int digit = number / (int) pow(10, index) % 10;
    return digit;
}

void handleTensLogic(int number) {
    const int remainder = (number % 100);
    if (remainder < 20) {
        printTeenNumbers(remainder);
        return;
    }

    int currentDigit = getDigitFromIndex(number, secondDigitIdx);
    printTens(currentDigit);

    currentDigit = getDigitFromIndex(number, firstDigitIdx);
    std::cout << " ";
    printDigit(currentDigit);
}

int main() {
    int number = 0;
    std::cin >> number;

    if (number == 0) {
        std::cout << "zero";
    } else if (number < 10) {
        printDigit(number);
        return 0;
    } else if (number < 20) {
        printTeenNumbers(number);
    } else if (number < 100) {
        handleTensLogic(number);
    } else {
        int currDigit = getDigitFromIndex(number, thitdDigitIdx);
        printDigit(currDigit);
        std::cout << " hundred ";
        handleTensLogic(number);
    }

    return 0;
}
