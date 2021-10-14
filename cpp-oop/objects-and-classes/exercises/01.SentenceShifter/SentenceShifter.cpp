#include <iostream>
#include <string>
#include <sstream>
#include <queue>

class SentenceShifter {
public:
    SentenceShifter() : _words {}, _numShuffles(0) {}

    SentenceShifter(std::deque<std::string> words, int numShifts) {
        this->_words = words;
        this->_numShuffles = numShifts;
    }

    void shuffleWords() {
        for (int i = 0; i < _numShuffles; i++) {
            const std::string lastWord = _words.back();
            _words.pop_back();
            _words.push_front(lastWord);
        }
    }

    std::deque<std::string> getShiftedSentence() const {
        return _words;
    }

private:
    std::deque<std::string> _words;
    int _numShuffles;
};

std::deque<std::string> readInput() {
    std::deque<std::string> wordsDeque;

    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);

    std::string word;
    while (istr >> word) {
        wordsDeque.push_back(word);
    }

    return wordsDeque;
}

int main() {
    std::deque<std::string> wordsDeque = readInput();

    int numShuffles;
    std::cin >> numShuffles;
    std::cin.ignore();

    SentenceShifter shifter(wordsDeque, numShuffles);

    shifter.shuffleWords();

    std::deque<std::string> shiftedWords = shifter.getShiftedSentence();

    for (const auto& word : shiftedWords) {
        std::cout << word << std::endl;
    }

    return 0;
}
