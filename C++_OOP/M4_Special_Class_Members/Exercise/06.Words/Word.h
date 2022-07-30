#ifndef WORD_H
#define WORD_H

#include <unordered_map>
#include <set>
#include <string>

class Word {
public:
    Word(const std::string& word);

    std::string getWord() const;

    int getCount() const;

    bool operator<(const Word& otherWord) const;

private:
    std::string _currWord;
    // static std::unordered_map<std::string, int> _wordsMap;
    static std::multiset<std::string> _wordsSet;
};

#endif // !WORD_H
