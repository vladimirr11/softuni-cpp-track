#include <iostream>
#include <array>
#include <string>
#include <sstream>

const int maxSize = 1000;

std::string getInputString() {
    std::string line;
    getline(std::cin, line);
    return line; 
}

void printResult(const std::array<std::string, maxSize>& digitArr, const int& arrSize) {
    int maxNumber = INT16_MIN;
    for (int i = 0; i < arrSize; i++) {
        if (stoi(digitArr[i]) > maxNumber) {
            maxNumber = stoi(digitArr[i]);
        }
    }
    std::cout << maxNumber << std::endl;
}

void parseLine(std::istringstream& stream) {
    int arraySize = 0;
    std::array<std::string, maxSize> digitArray;

    std::string str;
    while (!stream.eof()) {
        stream >> str;

        std::string conctDigit;
        for (int i = 0; i < str.size(); i++) {
            if (isdigit(str[i])) {
                conctDigit += str[i];
            }
        }
        digitArray[arraySize] = conctDigit;
        arraySize++;
    }

    printResult(digitArray, arraySize);
}

int main() {
    std::string line = getInputString();

    std::istringstream stream(line);
    
    parseLine(stream);

    return 0;
}
