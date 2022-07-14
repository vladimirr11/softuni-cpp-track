#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>

class Message {
public:
    Message() = default;

    void read() {
        std::string text;
        getline(std::cin, text);
        std::istringstream istr(text);

        std::string word;
        while (istr >> word) {
            size_t wordSize = word.size();
            for (size_t i = 0; i < wordSize; i++) {
                if (ispunct(word[i])) {
                    word.erase(i--, 1);
                }
            }
            messageVec.push_back(word);
        }
    }

    std::vector<std::string> getWords() const { return messageVec; }

    std::set<std::string> getWordsWithChar(const char ch) {
        std::set<std::string> lexOrderedWords {};
        for (const auto& word : messageVec) {
            std::string wordCopy = word;
            std::transform(wordCopy.begin(), wordCopy.end(), wordCopy.begin(), [](const char c) {
                return std::tolower(c);
            });
            
            size_t found = wordCopy.find(ch);
            if (found != std::string::npos) {
                lexOrderedWords.insert(word);
            }
        }

        if (lexOrderedWords.empty()) {
            lexOrderedWords.insert("---");
        } 

        return lexOrderedWords;
    }

private:
    std::vector<std::string> messageVec {};
};

class TargetChars {
public:
    TargetChars() = default;

    void read() {
        char inputChar;
        while (true) {
            std::cin >> inputChar;
            inputChar = std::tolower(inputChar);
            if (inputChar == '.') {
                break;
            }
            targetChars.push_back(inputChar);
        }
    }

    std::vector<char> getTargets() const { return targetChars; }

private:
    std::vector<char> targetChars {};
};

int main() {
    Message message;
    message.read();

    TargetChars tchars;
    tchars.read();

    for (const auto& tc : tchars.getTargets()) {
        auto words = message.getWordsWithChar(tc);
        for (const auto& w : words) {
            std::cout << w << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
