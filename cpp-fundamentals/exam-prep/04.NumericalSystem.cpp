#include <iostream>
#include <string>
#include <array>

const int arrSize = 255;

void readInput(std::string& numSystem, std::string& firstNum, std::string& secondNum) {
    std::cin >> numSystem >> firstNum >> secondNum;
}

std::array<int, arrSize> convertNumericlaSystemToDigits(const std::string& numSystem) {
    std::array<int, arrSize> arr{};

    const size_t size = numSystem.size();
    for (size_t i = 0; i < size; i++) {
        const int idx = numSystem[i];
        arr[idx] = i;
    }

    return arr;
}

int getIntFromString(const std::string& numberStr, const std::array<int, arrSize>& intDigits) {
    int number = 0;
    for (const char digit : numberStr) {
        number *= 10;
        number += intDigits[digit];
    }

    return number;
}

int getIntFromChar(char c) {
    return c - '0';
}

std::string getNumericalSystemRepresentationFromIntiger(const std::string& numSystem, int number) {
    std::string numberRepresantationStr;

    const std::string numberStr = std::to_string(number);
    for (const char letter : numberStr) {
        const int digitIndex = getIntFromChar(letter);
        const char newLetter = numSystem[digitIndex];
        numberRepresantationStr.push_back(newLetter);
    }

    return numberRepresantationStr;
}

int main() {
    std::string numericalSystem;
    std::string firstNumberAsStr;
    std::string secondNumberAsStr;

    readInput(numericalSystem, firstNumberAsStr, secondNumberAsStr);

    const std::array<int, arrSize> intDigits = convertNumericlaSystemToDigits(numericalSystem);
    const int firstNumber = getIntFromString(firstNumberAsStr, intDigits);
    const int secondNumber = getIntFromString(secondNumberAsStr, intDigits);

    const int sum = firstNumber + secondNumber;

    const std::string numberRepresantationStr = getNumericalSystemRepresentationFromIntiger(numericalSystem, sum);

    std::cout << numberRepresantationStr << std::endl;

    return 0;
}