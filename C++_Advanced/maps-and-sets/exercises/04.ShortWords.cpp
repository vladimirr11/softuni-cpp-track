#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <bits/stdc++.h>

const size_t WORDS_SIZE = 5;

std::set<std::string> getInputWords() {
    std::set<std::string> inputWords;

    std::string iLine;
    getline(std::cin, iLine);
    std::istringstream iStream(iLine);

    std::string word;
    while (iStream >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        inputWords.insert(word);
    }

    return inputWords;
}

int main() {
    std::set<std::string> words = getInputWords();

    std::string answer;
    for (auto const& word : words) {
        if (word.size() < WORDS_SIZE) {
            answer.append(word).append(", ");
        }
    }

    answer.pop_back();
    answer.pop_back();
    std::cout << answer << std::endl;

    return 0;
}
