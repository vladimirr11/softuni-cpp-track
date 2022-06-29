#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

std::unordered_map<std::string, int> readInputAndConvertToMap() {
    std::unordered_map<std::string, int> messageWordsCount {};

    std::string line;
    getline(std::cin, line);

    std::size_t found = line.find(" .");
    if (found != std::string::npos) {
        line.erase(found);
    }

    std::istringstream istr(line);

    std::string currWord;
    while (istr >> currWord) {
        messageWordsCount[currWord]++;
    }

    return messageWordsCount;
}

std::vector<std::pair<int, int>> readQueries() {
    int numQueries = 0;
    std::cin >> numQueries;
    
    std::vector<std::pair<int, int>> quereisVec {};
    quereisVec.reserve(numQueries);
    for (int i = 0; i < numQueries; i++) {
        int wordCount, index;
        std::cin >> wordCount >> index;

        quereisVec.push_back(std::make_pair(wordCount, index));
    }

    return quereisVec;
}

void prepareAndPrintSolution(std::unordered_map<std::string, int>& messageWordsCount,
                            std::vector<std::pair<int, int>>& quereisVec) {
    
    for (auto query : quereisVec) {
        std::vector<std::string> currQuery {};
        for (auto pair : messageWordsCount) {
            if (pair.second == query.first) {
                currQuery.push_back(pair.first);
            }
        }
        std::cout << currQuery[query.second] << std::endl;
    }
}

int main() {
    std::unordered_map<std::string, int> messageWordsCount = readInputAndConvertToMap();

    std::vector<std::pair<int, int>> quereisVec = readQueries();

    prepareAndPrintSolution(messageWordsCount, quereisVec);

    return 0;
}
