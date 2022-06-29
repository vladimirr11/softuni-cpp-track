#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>

const size_t TARGET_COUNT = 3;

std::set<double, std::greater<double>> getInputNumbers() {
    std::set<double, std::greater<double>> nums;

    std::string iLine;
    getline(std::cin, iLine);
    std::istringstream iStream(iLine);

    double currNumber {};
    while (iStream >> currNumber) {
        nums.insert(currNumber);
    }

    return nums;
}

int main() {
    std::set<double, std::greater<double>> numbers = getInputNumbers();

    if (numbers.size() <= TARGET_COUNT) {
        for (auto it = numbers.begin(); it != numbers.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    } else {
        auto it = numbers.begin();
        for (size_t i = 0; i < TARGET_COUNT; i++) {
            std::cout << *it << " ";
            std::advance(it, 1);
        }
        std::cout << std::endl;
    }

    return 0;
}
