#include "StringWrapper.h"

StringWrapper::StringWrapper() {}

StringWrapper::StringWrapper(const std::string& str) : _line(str) {}

StringWrapper::StringWrapper(char c, int rep) : _c(c), _rep(rep) {
    for (int i = 0; i < _rep; i++) {
        _line.push_back(_c);
    }
}

std::string& StringWrapper::append(const std::string& str) {
    _line.append(str);
    return _line;
}

std::string StringWrapper::getContent() const {
    return _line;
}

void StringWrapper::printContent() {
    std::cout << _line << std::endl;
}
