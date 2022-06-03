#include <iostream>
#include <vector>
#include <string>

std::vector<int> vectorAfterOeprationSum(std::vector<int>& vec) {
    int firstEl = vec.back();
    vec.pop_back();
    int secondEl = vec.back();
    vec.pop_back();

    int sum = firstEl + secondEl;
    vec.push_back(sum);

    return vec;
}

std::vector<int> vectorAfterOeprationSubtract(std::vector<int>& vec) {
    int lastEl = vec.back();
    vec.pop_back();
    int secondLastEl = vec.back();
    vec.pop_back();

    int resultAfterSubtracion = lastEl - secondLastEl;
    vec.push_back(resultAfterSubtracion);

    return vec;
}

std::vector<int> vectorAfterOeprationConcat(std::vector<int>& vec) {
    int lastEl = vec.back();
    vec.pop_back();
    int secondLastEl = vec.back();
    vec.pop_back();

    std::string resultConcat = std::to_string(secondLastEl) + std::to_string(lastEl);
    vec.push_back(stoi(resultConcat));

    return vec;
}

std::vector<int> vectorAfterOeprationDiscard(std::vector<int>& vec) {
    int lastEl = vec.back();
    vec.pop_back();

    return vec;
}

void doOperationsWithVec(std::vector<int>& vec) {
    while (true) {
        std::string inputString;
        std::cin >> inputString;
        if (inputString == "end") {
            break;
        } else if (inputString == "sum") {
            vectorAfterOeprationSum(vec);
        } else if (inputString == "subtract") {
            vectorAfterOeprationSubtract(vec);
        } else if (inputString == "concat") {
            vectorAfterOeprationConcat(vec);
        } else if (inputString == "discard") {
            vectorAfterOeprationDiscard(vec);
        } else {
            int numToInsert = stoi(inputString);
            vec.push_back(numToInsert);
        }
    }
}

void printVector(const std::vector<int>& vec) {
    size_t vecSize= vec.size();
    for (size_t i = 0; i < vecSize; i++) {
        std::cout << vec[i] << std::endl;
    }
}

int main() {
    std::vector<int> vec;

    doOperationsWithVec(vec);

    printVector(vec);

    return 0;
}
