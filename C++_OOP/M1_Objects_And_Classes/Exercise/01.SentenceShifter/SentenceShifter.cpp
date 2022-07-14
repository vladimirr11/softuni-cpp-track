#include <iostream>
#include <string>
#include <sstream>
#include <queue>

class SentenceShifter {
public:
    SentenceShifter() = default;

    void readWords(std::istream& istr);

    void shuffleWords(int _numShuffles);

    std::string print() const;

private:
    std::deque<std::string> _words;
};

void SentenceShifter::readWords(std::istream& istr) {
    std::string iline;
    getline(istr, iline);

    std::istringstream stream(iline);
    std::string word;
    while (stream >> word) {
        _words.push_back(word);
    }
}

void SentenceShifter::shuffleWords(int _numShuffles) {
    for (int i = 0; i < _numShuffles; i++) {
        const std::string lastWord = _words.back();
        _words.pop_back();
        _words.push_front(lastWord);
    }
}

std::string SentenceShifter::print() const {
    std::ostringstream ostr;
    for (const std::string& w : _words) {
        ostr << w << std::endl;
    }
    return ostr.str();
}

int main() {
    SentenceShifter sentShifter;
    sentShifter.readWords(std::cin);

    int numShuffles;
    std::cin >> numShuffles;
    std::cin.ignore();

    sentShifter.shuffleWords(numShuffles);

    std::cout << sentShifter.print();

    return 0;
}
