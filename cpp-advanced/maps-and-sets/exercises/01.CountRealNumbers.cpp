#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

std::vector<double> getInputNumbers() {
    std::vector<double> vec;

    std::string iLine;
    getline(std::cin, iLine);
    std::istringstream iStream(iLine);

    double currNumber = 0.0;
    while (iStream >> currNumber) {
        vec.push_back(currNumber);
    }

    return vec;
}


int main() {
    std::vector<double> iVec = getInputNumbers();

    std::map<double, int> numbersCountMap = {};

    for (double number : iVec) {
        numbersCountMap[number]++;
    }

    for (auto num : numbersCountMap) {
        std::cout << num.first << " -> " << num.second << std::endl;
    }

    return 0;
}
