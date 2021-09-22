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

void capitalizeWordFirstLetter(std::string& text) {
    bool wordStarted = false;
    size_t wordIndex = 0;

    int texteLength = text.size();
    for (size_t i = 0; i < texteLength; i++) {
        if (isalpha(text[i])) {
            if (!wordStarted) {
                wordStarted = true;
                wordIndex = i;
            }
            continue;
        } 
    
        text[wordIndex] = toupper(text[wordIndex]);
        wordStarted = false;
    }

    if (wordStarted) {
        text[wordIndex] = toupper(text[wordIndex]);
    }
}

int main() {

    std::string sentence = getInputString();

    capitalizeWordFirstLetter(sentence);

    std::cout << sentence << std::endl;

    return 0;
}