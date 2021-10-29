#ifndef TRYPARSE_H
#define TRYPARSE_H

#include <string>

bool tryParse(const std::string& str, int& num) {
    bool isNumber = true;
    for (const char ch : str) {
        if (ch == '-') {
            continue;
        } else if (!isdigit(ch)) {
            isNumber = false;
            break;
        }
    }

    if (isNumber) {
        num = stoi(str);
        return true;
    }

    return false;
}

#endif // !TRYPARSE_H
