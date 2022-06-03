#include <iostream>
#include <array>
#include <string>
#include <sstream>

std::string getInputString() {
    std::string line;
    getline(std::cin, line);
    return line;
}

std::string replacePartsOfText(std::string& sentence, std::string& wordToReplace,
                               std::string& wordToInsert) {
    size_t index = 0;
    while (index != std::string::npos) {
        index = sentence.find(wordToReplace, index + 1);
        if (index >= sentence.size()) {
            break;
        }
        sentence.replace(index, wordToReplace.size(), wordToInsert);
    }

    return sentence;
}

int main() {
    std::string inputString = getInputString();
    std::string stringToFind = getInputString();
    std::string stringToReplace = getInputString();
    
    replacePartsOfText(inputString, stringToFind, stringToReplace);

    std::cout << inputString << std::endl;

    return 0;
}
