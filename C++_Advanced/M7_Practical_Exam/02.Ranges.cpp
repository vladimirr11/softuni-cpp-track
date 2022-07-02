#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

std::map<int, int> readRanges() {
    std::map<int, int> rangesMap {};
    while (true) {
        std::string line;
        getline(std::cin, line);
        if (line == ".") {
            break;
        }

        std::istringstream istr(line);

        int from {}, to {};
        istr >> from >> to;

        rangesMap[from] = to;
    }

    return rangesMap;
}

std::vector<int> readNumsToCheck() {
    std::vector<int> numsVec{};
    while (true) {
        std::string line;
        getline(std::cin, line);
        if (line == ".") {
            break;
        }

        std::istringstream istr(line);
        int num;
        istr >> num;

        numsVec.push_back(num);
    }

    return numsVec;
}

void checkIfNumInRange(const std::map<int, int>& rangesMap, const std::vector<int>& numsToCheck) {
    for (const int num : numsToCheck) {
        auto upperB = rangesMap.upper_bound(num);
        upperB--;
        if (upperB->first <= num && num <= upperB->second) {
            std::cout << "in" << std::endl;
        } else {
            std::cout << "out" << std::endl;
        }
    }
}

int main() {
    std::map<int, int> rangesMap = readRanges();
    std::vector<int> numsToCheck = readNumsToCheck();

    checkIfNumInRange(rangesMap, numsToCheck);

    return 0;
}
