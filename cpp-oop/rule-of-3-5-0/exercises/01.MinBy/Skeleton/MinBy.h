#ifndef MINBY_H
#define MINBY_H

#include <iostream>
#include <vector>
#include <string>
#include <functional>

std::string minBy(std::vector<std::string>& values,
                  std::function<bool(const std::string&, const std::string&)> callbackFunc) {
    
    std::string minString = values[0];
    for (size_t i = 1; i < values.size(); i++) {
        std::string currString = values[i];
        if (callbackFunc(currString, minString)) {
            minString = currString;
        }
    }

    return minString;
}

#endif // !MINBY_H
