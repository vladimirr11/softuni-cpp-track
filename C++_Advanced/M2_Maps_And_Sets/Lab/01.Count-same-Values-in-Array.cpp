#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

std::vector<double> getInputArray() {
    std::vector<double> vec;

    std::string iLine;
    getline(std::cin >> std::ws, iLine);
    std::istringstream iStream(iLine);

    double currNumber {};
    while (iStream >> currNumber) {
        vec.push_back(currNumber);
    }

    return vec;
}

int main() {
    std::vector<double> iVec = getInputArray();

    std::unordered_map<double, int> arrValuesMap {};

    for (double number : iVec) {
        arrValuesMap[number]++;
    }

    for (auto num : arrValuesMap) {
        std::cout << num.first << " - " << num.second << " times"<< std::endl;
    }

    return 0;
}
