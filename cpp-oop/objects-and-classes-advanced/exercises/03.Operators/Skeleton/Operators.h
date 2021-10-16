#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>

std::string operator+(std::string& line, int index) {
    std::string strIndex = std::to_string(index);
    return line + strIndex;
}

std::vector<std::string>& operator<<(std::vector<std::string>& vec, std::string& str) {
    vec.push_back(str + "\n");
    return vec;
}

std::ostream& operator<<(std::ostream& outputStream, const std::vector<std::string>& vec) {
    for (const std::string& str : vec) {
        outputStream << str;
    }
    return outputStream;
}

#endif // !OPERATORS_H
