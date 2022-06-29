#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

std::vector<std::string> getInputWords() {
    std::vector<std::string> wordsVec;

    std::string iLine;
    getline(std::cin, iLine);
    std::istringstream iStream(iLine);

    std::string currWord;
    while (iStream >> currWord) {
        std::transform(currWord.begin(), currWord.end(), currWord.begin(), tolower);
        wordsVec.push_back(currWord);
    }

    return wordsVec;
}

void filterWordsCountAndPrintResult(std::vector<std::string>& wordsVec, std::map<std::string, int>& wordsCounts) {
    std::string answer;
    for (const auto& word : wordsVec) {
        auto wordsIt = wordsCounts.find(word);
        if (wordsIt != wordsCounts.end() && wordsIt->second % 2 != 0) {
            answer.append(wordsIt->first).append(", ");
            wordsCounts.erase(wordsIt);
        }
    }

    answer.pop_back();
    answer.pop_back();
    std::cout << answer << std::endl;
}

int main() {
    std::vector<std::string> wordsVec = getInputWords();

    std::map<std::string, int> wordsCounts = {};

    for (const auto& word : wordsVec) {
        wordsCounts[word]++;
    }

    filterWordsCountAndPrintResult(wordsVec, wordsCounts);
    
    return 0;
}
