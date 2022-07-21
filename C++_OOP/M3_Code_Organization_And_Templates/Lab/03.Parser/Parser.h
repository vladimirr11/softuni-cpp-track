#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <sstream>

template<typename Type>
class Parser {
public:
    Parser(std::istream& istr, const std::string& stopSign); 

    bool readNext(Type& nextEl);

private:
    std::istream& _inputEl;
    std::string _stopSign;
};

template<typename Type>
Parser<Type>::Parser(std::istream& istr, const std::string& stopSign) : _inputEl(istr), _stopSign(stopSign) {}

template<typename Type>
bool Parser<Type>::readNext(Type& nextEl) {
    std::string currLine;
    std::getline(_inputEl, currLine);
    if (currLine != _stopSign) {
        std::istringstream istr(currLine);
        istr >> nextEl;
        return true;
    }    
    return false;
}

#endif // !PARSER_H
