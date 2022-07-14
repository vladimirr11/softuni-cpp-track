#include "InputParser.h"

#include <iostream>
#include <sstream>

FieldData InputParser::readField() const {
    int numRows = 0, numCols = 0;
    std::cin >> numRows >> numCols;
    std::cin.ignore();

    FieldData fData;
    fData.reserve(numRows);
    for (int i = 0; i < numRows; i++) {
        std::string currStr;
        getline(std::cin, currStr);
        fData.push_back(currStr);
    }

    return fData;
}

std::vector<Command> InputParser::readCommands() const {
    int numCommands = 0;
    std::cin >> numCommands;
    std::cin.ignore();

    std::vector<Command> commandsVec;
    commandsVec.reserve(numCommands);

    for (int i = 0; i < numCommands; i++) {
        std::string currCommandLine;
        getline(std::cin, currCommandLine);

        std::istringstream istr(currCommandLine);

        std::string command;
        std::string commandEnd;

        istr >> command;

        if (command == "power") {
            istr >> commandEnd;
            if (commandEnd == "up") {
                Command cUp;
                cUp.type = CommandType::POWER_UP;
                commandsVec.push_back(cUp);
            } else {
                Command cDown;
                cDown.type = CommandType::POWER_DOWN;
                commandsVec.push_back(cDown);
            }

        } else if (command == "bomb") {
            int rowIdx = 0, colIdx = 0;
            istr >> rowIdx >> colIdx;
            Command placeBomb;
            placeBomb.type = CommandType::PLACE_BOMB;
            placeBomb.bombRow = rowIdx;
            placeBomb.bombCol = colIdx;

            commandsVec.push_back(placeBomb);
        }
    }

    return commandsVec;
}
