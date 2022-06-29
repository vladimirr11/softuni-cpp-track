#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::pair<int, int>> readRanges() {
    std::vector<std::pair<int, int>> rangesVec{};

    while (true) {
        std::string line;
        getline(std::cin, line);
        if (line == ".") {
            break;
        }

        std::istringstream istr(line);

        int from = 0, to = 0;

        istr >> from >> to;

        rangesVec.push_back(std::make_pair(from, to));
    }

    return rangesVec;
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

void preparaAndPrintSolution(std::vector<std::pair<int, int>>& rangesVec, std::vector<int>& numsToCheck) {

    size_t size = rangesVec.size();
    for (auto num : numsToCheck) {
        bool isInRange = false;
        for (size_t i = 0; i < size; i++) {
            if (num >= rangesVec[i].first && num <= rangesVec[i].second) {
                isInRange = true;
                break;
            }
        }

        if (isInRange) {
            std::cout << "in" << std::endl;
        } else {
            std::cout << "out" << std::endl;
        }

    }
}

int main() {
    std::vector<std::pair<int, int>> rangesVec = readRanges();

    std::vector<int> numsToCheck = readNumsToCheck();

    preparaAndPrintSolution(rangesVec, numsToCheck);

    return 0;
}
