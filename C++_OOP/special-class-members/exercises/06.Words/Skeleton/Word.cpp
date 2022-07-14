#include <string>
#include <unordered_map>

#include "Word.h"

// std::unordered_map<std::string, int> Word::_wordsMap{};
std::multiset<std::string> Word::_wordsSet{};

Word::Word(const std::string& word) : _currWord(word) {
    // _wordsMap[_currWord]++;
    _wordsSet.insert(_currWord);
}

bool Word::operator<(const Word& otherWord) const {
    return _currWord < otherWord.getWord();
}

std::string Word::getWord() const {
    return _currWord;
}

int Word::getCount() const {    
    // const int count = _wordsMap[_currWord];
    // _wordsMap[_currWord] = 0;

    // return count;

    return _wordsSet.erase(_currWord);
}
