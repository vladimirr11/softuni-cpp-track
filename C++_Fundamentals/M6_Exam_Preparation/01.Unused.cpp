#include <iostream>
#include <array>
#include <string>

const int maxSize = 26;

std::string getInputString() {
    std::string line;
    getline(std::cin, line);
    return line;
}

void checkIfLetterInString(std::string& inputStr, std::array<bool, maxSize>& alphabet) {
    for (char letter : inputStr) {
        const int letterIdx = letter - 'a';
        alphabet[letterIdx] = true;
    }
}

void printMissingLettersFromString(const std::array<bool, maxSize>& alphabet) {
    const size_t length = alphabet.size();
    for (size_t i = 0; i < length; i++) {
        if (!alphabet[i]) {
            std::cout << char(i + 'a');
        }
    }
}

int main() {    
    std::string inputString = getInputString();

    std::array<bool, maxSize> alphabet {};
    checkIfLetterInString(inputString, alphabet);

    printMissingLettersFromString(alphabet);

    return 0;
}
