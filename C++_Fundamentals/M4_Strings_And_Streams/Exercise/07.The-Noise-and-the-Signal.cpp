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

void parseLine(std::istringstream& stream, 
               std::array<std::string, maxSize>& charsArr, int& arraySize) {
    std::string str;
    while (!stream.eof()) {
        stream >> str;

        std::string concatChars;
        for (int i = 0; i < str.size(); i++) {
            if (!isdigit(str[i])) {
                concatChars += str[i];
            }
        }

        charsArr[arraySize] = concatChars;
        arraySize++;
    }
}

void getNoiseFromString(std::array<std::string, maxSize>& charsArray, int& arraySize) {
    std::string longestNoise;
    int maxLength = INT16_MIN;

    for (int i = 0; i < arraySize; i++) {
        if (((int) charsArray[i].size()) >= maxLength) {
            if (charsArray[i].size() == longestNoise.size()) {
                if (charsArray[i] < longestNoise) {
                    longestNoise = charsArray[i];
                }
            } else {
                longestNoise = charsArray[i];
                maxLength = charsArray[i].size();
            }
        }
    }

    if (maxLength == INT16_MIN) {
        std::cout << "no noise" << std::endl;
    } else {
        std::cout << longestNoise << std::endl;
    }
}

int main() {
    std::string line = getInputString();

    std::istringstream stream(line);

    int arrSize = 0;
    std::array<std::string, maxSize> charsArray {};
    
    parseLine(stream, charsArray, arrSize);

    getNoiseFromString(charsArray, arrSize);

    return 0;
}
