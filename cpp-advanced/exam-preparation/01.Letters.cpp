#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>

std::vector<std::string> readText () {
    std::vector<std::string> textVec {};

    std::string text;
    getline(std::cin, text);

    std::istringstream istream(text);

    std::string word;
    while (istream >> word) {
        for (int i = 0; i < word.size(); i++) {
            if (ispunct(word[i])) {
                word.erase(i--, 1);
            }
        }
        textVec.push_back(word);
    }

    return textVec;
}

std::vector<char> readChars () {
    std::vector<char> charsVec {};

    char inputChar;
    while (true) {
        std::cin >> inputChar;
        inputChar = std::tolower(inputChar);
        if (inputChar == '.') {
            break;
        }
        
        charsVec.push_back(inputChar);
    }

    return charsVec;
}

std::vector<std::set<std::string>> prepareSolution(std::vector<std::string>& wordsVec, 
                            std::vector<char>& charsVec) {

    std::vector<std::set<std::string>> vecsForPrint {};

    for (auto ch : charsVec) {
        std::set<std::string> wordsSet {};
        for (auto word : wordsVec) {
            std::string wordCopy = word;
            std::transform(wordCopy.begin(), wordCopy.end(), wordCopy.begin(), 
                                [](unsigned char c){return std::tolower(c);});
            size_t found = wordCopy.find(ch);
            if (found != std::string::npos) {
                wordsSet.insert(word);
            }
        }
        if (wordsSet.empty()) {
            wordsSet.insert("---");
        } 
        vecsForPrint.push_back(wordsSet);
    }

    return vecsForPrint;
}

void printSolution(const std::vector<std::set<std::string>>& vec2DWithSets) {
    for (auto set : vec2DWithSets) {
        for (auto word : set) {
            std::cout << word << ' ';
        } std::cout << std::endl;
    }
}

int main() {
    std::vector<std::string> wordsVec = readText();
    std::vector<char> charsVec = readChars();

    std::vector<std::set<std::string>> vec2DWithSets = prepareSolution(wordsVec, charsVec);

    printSolution(vec2DWithSets);

    return 0;
}
