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

void parseLine(std::istringstream& stream, int& arrSize,
                std::array<std::string, maxSize>& strArr, int& sum) {
    int digit = 0;
    std::string str;
    while (!stream.eof()) {
        stream >> str;
        if (std::stringstream(str) >> digit) {
            sum += digit;
        } else {
            strArr[arrSize] = str;
            arrSize++;
        }
    }
}

void printResult(const int& sum, const std::array<std::string, maxSize>& strArr, const int& arrSize) {
    std::cout << sum << std::endl;
    for (int i = 0; i < arrSize; i++) {
        std::cout << strArr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::string line = getInputString();

    std::istringstream stream(line);
    int arrSize = 0;
    std::array<std::string, maxSize> stringArray;

    int sum = 0;
    parseLine(stream, arrSize, stringArray, sum);

    printResult(sum, stringArray, arrSize);

    return 0;
}
