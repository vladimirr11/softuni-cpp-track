#include "InputParser.h"

#include <string>
#include <iostream>

Input readInput() {
    std::string str;
    char letter {};
    int rep = 0;

    std::cin >> str >> letter >> rep;

    Input input { str, letter, rep };

    return input;
}
