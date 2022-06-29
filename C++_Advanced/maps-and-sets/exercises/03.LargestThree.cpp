#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

const size_t TARGET_COUNT_OF_NUMBERS = 3;

std::priority_queue<double> getInputNumbers() {
    std::priority_queue<double> priorityQueue;

    std::string iLine;
    getline(std::cin, iLine);
    std::istringstream iStream(iLine);

    double currNumber = 0.0;
    while (iStream >> currNumber) {
        priorityQueue.push(currNumber);
    }

    return priorityQueue;
}

int main() {
    std::priority_queue<double> numbersQueue = getInputNumbers();

    size_t queueSize = numbersQueue.size();

    if (queueSize <= TARGET_COUNT_OF_NUMBERS) {
        for (size_t i = 0; i < queueSize; i++) {
        std::cout << numbersQueue.top() << " ";
        numbersQueue.pop();
    }
    std::cout << std::endl;
    } else {
        for (size_t i = 0; i < TARGET_COUNT_OF_NUMBERS; i++) {
        std::cout << numbersQueue.top() << " ";
        numbersQueue.pop();
    }
    std::cout << std::endl;
    }

    return 0;
}
