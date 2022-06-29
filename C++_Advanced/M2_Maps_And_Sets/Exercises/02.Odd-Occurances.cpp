#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <tuple>

using vec_map_tuple = std::tuple<std::vector<std::string>, std::map<std::string, int>>;

vec_map_tuple getInput() {
    std::vector<std::string> wordsVec {};
    std::map<std::string, int> wordsMap {};

    std::string iLine;
    getline(std::cin, iLine);
    std::istringstream iStream(iLine);

    std::string currWord;
    while (iStream >> currWord) {
        std::transform(currWord.begin(), currWord.end(), currWord.begin(), tolower);
        wordsVec.push_back(currWord);
        wordsMap[currWord]++;
    }

    return std::make_tuple(wordsVec, wordsMap);
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
    vec_map_tuple myTuple = getInput();

    auto wordsVec = std::get<0>(myTuple);
    auto wordsMap = std::get<1>(myTuple);
    
    filterWordsCountAndPrintResult(wordsVec, wordsMap);
    
    return 0;
}
