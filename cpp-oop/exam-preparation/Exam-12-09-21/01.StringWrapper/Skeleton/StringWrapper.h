#ifndef STRINGWRAPPER_H
#define STRINGWRAPPER_H

#include <string>
#include <iostream>

class StringWrapper {
public:
    StringWrapper();

    StringWrapper(const std::string& str);

    StringWrapper(char c, int rep);

    std::string& append(const std::string& str);

    std::string getContent() const;

    void printContent();

private:
    std::string _line;
    char _c;
    int _rep;

};

#endif // !STRINGWRAPPER_H
