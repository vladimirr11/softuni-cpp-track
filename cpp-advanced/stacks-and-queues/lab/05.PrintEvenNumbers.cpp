#include <iostream>
#include <string>
#include <sstream>
#include <queue>

std::queue<int> getInputQueue() {
    std::queue<int> queue;

    std::string line;
    getline(std::cin, line);
    
    std::istringstream stream(line);

    int currNumber = 0;
    while (stream >> currNumber) {
        queue.push(currNumber);
    }

    return queue;
}

int main() {
    std::queue<int> inputQueue = getInputQueue();

    std::queue<int> outputQueue;
    while (!inputQueue.empty()) {
        int currNumber = inputQueue.front();
        if (currNumber % 2 == 0) {
            outputQueue.push(currNumber);
        }
        inputQueue.pop();
    }

    while (!outputQueue.empty()) {
        int currEvenNumber = outputQueue.front();
        outputQueue.pop();
        if (outputQueue.empty()) {
            std::cout << currEvenNumber << std::endl;
            break;
        }
        std::cout << currEvenNumber << ", ";
    }

    return 0;
}
