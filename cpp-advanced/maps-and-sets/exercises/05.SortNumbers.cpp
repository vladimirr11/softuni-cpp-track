#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>

std::set<double> getInputNumbers() {
    std::set<double> inputNumbers;

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
    std::set<double> numbers = getInputNumbers();

    std::string answer;
    for (const auto& num : numbers) {
        answer.append(std::to_string(int(num))).append(" <= ");
    }

    const int CHAR_TO_REMOVE = 4;
    for (int i = 0; i < CHAR_TO_REMOVE; i++) {
        answer.pop_back();
    }

    std::cout << answer << std::endl;

    return 0;
}
