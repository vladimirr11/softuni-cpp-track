#ifndef SPLIT_H
#define SPLIT_H

#include <vector>
#include <sstream>

template<typename Type>
Type parseSubstr(const std::string& line, size_t startIdx, size_t length) {
    std::string subStr = line.substr(startIdx, length);
    std::istringstream istr(subStr);
    Type el;
    istr >> el;
    return el;
}

template<typename Type>
std::vector<Type> split(std::string& line, char separator) {
    std::vector<Type> vec;

    size_t startIdx = 0;
    for (size_t i = 0; i < line.size(); i++) {
        if (line[i] == separator) {
            vec.push_back(parseSubstr<Type>(line, startIdx, i - startIdx));
            startIdx = i + 1;
        }
    }

    vec.push_back(parseSubstr<Type>(line, startIdx, line.size() - startIdx));

    return vec;
}

#endif // !SPLIT_H
