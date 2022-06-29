#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<int> getInputNumbers() {
    std::vector<int> inputNumbers;

    std::string iLine;
    getline(std::cin, iLine);
    std::istringstream iStream(iLine);

    int currNumber;
    while (iStream >> currNumber) {
        inputNumbers.push_back(currNumber);
    }

    return inputNumbers;
}

int main() {
    std::vector<int> numbers = getInputNumbers();

    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    for (const auto& num : numbers) {
        int root = std::sqrt(num);
        if (std::pow(root, 2) == num) {
            std::cout << num << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
