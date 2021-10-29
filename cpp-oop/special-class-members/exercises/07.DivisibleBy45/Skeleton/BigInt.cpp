#include <iostream>
#include <array>
#include <string>

#include "BigInt.h"

constexpr int ARR_SIZE = 2;

std::array<BigInt, ARR_SIZE> readInput() {
    std::array<std::string, ARR_SIZE> stringInput{};
    std::cin >> stringInput[0] >> stringInput[1];

    std::array<BigInt, ARR_SIZE> arr = { stringInput[0], stringInput[1] };

    return arr;
}

bool isDivisibleBy5(const BigInt& bigInt) {
    const std::string digits = bigInt.getDigits();

    if (!(digits.empty())) {
        const char lastChar = digits.back();
        if (lastChar == '0' || lastChar == '5') {
            return true;
        }
    }

    return false;
}

bool isDivisibleBy9(const BigInt& bigInt) {
    const std::string digits = bigInt.getDigits();

    int sumDigits = 0;
    for (const char ch : digits) {
        const int currNumber = ch - '0';
        sumDigits += currNumber;
    }

    if (sumDigits == 0) {
        return false;
    }

    if (sumDigits % 9 == 0) {
        return true;
    }

    return false;
}

bool isDivisibleBy45(const BigInt& bigInt) {
    return isDivisibleBy5(bigInt) && isDivisibleBy9(bigInt);
}

int main() {
    const auto numbers = readInput();
    const auto& start = numbers[0];
    const auto& end = numbers[1];
    const BigInt ONE(1);
    const BigInt FOURTY_FIVE(45);

    auto currNumber = start;

    for(; currNumber < end; currNumber += ONE) {
        if (isDivisibleBy45(currNumber)) {
            break;
        }
    }

    for(; currNumber < end; currNumber += FOURTY_FIVE) {
        std::cout << currNumber << std::endl;
    }

    return 0;
}
