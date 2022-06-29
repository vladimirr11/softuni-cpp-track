#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <sstream>
#include <map>

const std::string STOP_READ_DEL = ".";

std::vector<std::string> readInputCoordinates() {

    std::vector<std::string> coordsVec {};

    while (true) {
        std::string line;
        getline(std::cin, line);

        if (line == STOP_READ_DEL) {
            break;
        }

        coordsVec.push_back(line);
    }

    return coordsVec;
}

std::vector<std::string> readQuery() {
    std::vector<std::string> queryVec {};

    while (true) {
        std::string line;
        getline(std::cin, line);

        if (line == STOP_READ_DEL) {
            break;
        }

        queryVec.push_back(line);
    }

    return queryVec;
}

void findQueryInCoordVecAndPrintResult(std::vector<std::string>& coordsVec, std::vector<std::string>& queryVec) {

    for (auto query : queryVec) {
        std::istringstream stream(query);
        std::string firstQueryToken;
        stream >> firstQueryToken;
        
        for (auto coords : coordsVec) {
            std::size_t found = coords.find(firstQueryToken);
            if (found != std::string::npos) {
                std::cout << found << std::endl;
                std::cout << coords << std::endl;
            }
        }
    }
}

int main() {
    
    std::vector<std::string> coordsVec = readInputCoordinates();
    std::vector<std::string> queryVec = readQuery();

    findQueryInCoordVecAndPrintResult(coordsVec, queryVec);

    return 0;
}
