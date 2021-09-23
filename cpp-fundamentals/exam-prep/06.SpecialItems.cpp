#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::string getInputString() {
    std::string line;
    getline(std::cin, line);
    return line;
}

int main() {
    std::string line = getInputString();

    std::istringstream stream(line);

    std::vector<std::string> vec;

    std::string word;
    while (stream >> word) {
        vec.push_back(word);
    }

    for (std::string word : vec) {

        std::string newWord;
        for (size_t i = 0; i < word.size(); i++) {
            if (word[i] == 'e' || word[i] == 'a'|| word[i] == 'i'|| word[i] == 'o'|| word[i] == 'u') {
                newWord += word[i];
            } else {
                if (word[i] != word[i + 1]) {
                    newWord += word[i];
                }
            }
        }
        
        std::cout << newWord << ' ';
    }

    return 0;
}
