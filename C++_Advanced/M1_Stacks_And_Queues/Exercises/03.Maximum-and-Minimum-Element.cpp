#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

enum operations { ADD = 1, REMOVE, PRINT_MAX, PRINT_MIN };

std::queue<std::vector<int>> getInputQueries(int numQueries) {
    std::queue<std::vector<int>> queue;

    for (int i = 0; i < numQueries; i++) {
        std::string iline;
        getline(std::cin, iline);
        std::istringstream istream(iline);

        std::vector<int> vec;
        int currNum = 0;
        while (istream >> currNum) {
            vec.push_back(currNum);
        }

        queue.push(vec);
    }

    return queue;
}

void findMaxElementInStack(std::stack<int> stack) {
    if (stack.empty()) {
        return;
    }

    int maxEl = std::numeric_limits<int>::min();
    while (!stack.empty()) {
        int currEl = stack.top();
        stack.pop();
        if (currEl > maxEl) {
            maxEl = currEl;
        }
    }

    std::cout << maxEl << std::endl;
}

void findMinElementInStack(std::stack<int> stack) {
    if (stack.empty()) {
        return;
    }

    int minEl = std::numeric_limits<int>::max();
    while (!stack.empty()) {
        int currEl = stack.top();
        stack.pop();
        if (currEl < minEl) {
            minEl = currEl;
        }
    }

    std::cout << minEl << std::endl;
}

void printStack(std::stack<int>& stack) {
    if (stack.empty()) {
        return;
    }

    std::string answer;
    while (!stack.empty()) {
        answer.append(std::to_string(stack.top())).append(", ");
        stack.pop();
    }
    answer.pop_back();
    answer.pop_back();

    std::cout << answer << std::endl;
}

void parseQueries(std::queue<std::vector<int>>& queue) {
    std::stack<int> queriesStack;

    while (!queue.empty()) {
        std::vector<int> currQuery = queue.front();
        queue.pop();
        switch (currQuery[0]) {
            case ADD: 
                queriesStack.push(currQuery[1]);
                break;
            case REMOVE: 
                if (queriesStack.empty()) {
                    continue;
                }  
                queriesStack.pop();
                break;
            case PRINT_MAX: 
                findMaxElementInStack(queriesStack);
                break;
            case PRINT_MIN: 
                findMinElementInStack(queriesStack);
                break;
            default:
                std::cerr << "Error, received unsuported command " << currQuery[0] << std::endl;
                break; 
        }
    }

    printStack(queriesStack);
}

int main() {
    int numQueries {};
    std::cin >> numQueries;
    std::cin.ignore();

    std::queue<std::vector<int>> queue = getInputQueries(numQueries);

    parseQueries(queue);

    return 0;
}
