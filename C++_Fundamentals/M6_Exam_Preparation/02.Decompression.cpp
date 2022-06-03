#include <iostream>
#include <string>

std::string getInputString() {
    std::string line;
    getline(std::cin, line);
    return line;
}

int getIntFromChar(char c) {
    return c - '0';
}

std::string decompresString(const std::string& compressedString) {
    std::string decompressedString;

    int repetitions = 0;
    for (char letter : compressedString) {
        if (isdigit(letter)) {
            repetitions *= 10;
            repetitions += getIntFromChar(letter);
        } else {
            if (repetitions == 0) {
                decompressedString.push_back(letter);
            } else {
                const std::string mulitpleLetters(repetitions, letter);
                decompressedString.append(mulitpleLetters);
            }

            repetitions = 0;
        }
    }

    return decompressedString;
}

int main() {
    std::string compressedString = getInputString();
    std::string decompressedString = decompresString(compressedString);

    for (char c : decompressedString) {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
}
