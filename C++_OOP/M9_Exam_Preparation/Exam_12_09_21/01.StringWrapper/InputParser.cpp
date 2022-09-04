#include "InputParser.h"

#include <string>
#include <iostream>

Input readInput() {
    Input input;

    std::cin >> input.line >> input.letter >> input.repetitions;

    return input;
}
