#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <set>

std::set<int, std::greater<int>> getInputNumbers() {
    std::set<int, std::greater<int>> inputNumbers;

    std::string iLine;
    getline(std::cin, iLine);
    std::istringstream iStream(iLine);

    double currNumber;
    while (iStream >> currNumber) {
        inputNumbers.insert(currNumber);
    }

    return inputNumbers;
}

int main() {
    std::set<int, std::greater<int>> numbers = getInputNumbers();

    for (const auto& num : numbers) {
        int root = std::sqrt(num);
        if (std::pow(root, 2) == num) {
            std::cout << num << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
