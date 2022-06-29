#include <iostream>
#include <stack>
#include <limits>

std::stack<int> getInputStack(int number) {
    std::stack<int> stack;
    for (int i = 0; i < number; i++) {
        int currNumber {};
        std::cin >> currNumber;
        stack.push(currNumber);
    }

    return stack;
}

void popNElementsFromStack(std::stack<int>& stack, int N) {
    for (int i = 0; i < N; i++) {
        stack.pop();
    }
}

void findTarget(std::stack<int>& stack, int target) {
    if (stack.empty()) {
        std::cout << 0 << std::endl;
        return;
    }

    int minElem = std::numeric_limits<int>::max();
    bool isTarget = false;
    while (!stack.empty()) {
        int currNum = stack.top();
        stack.pop();

        if (currNum == target) {
            isTarget = true;
            break;
        } else {
            if (currNum < minElem) {
                minElem = currNum;
            }
        }
    }
    
    if (isTarget) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << minElem << std::endl;
    }
}

int main() {
    int numOfElemToPush = 0, numOfElemToPop = 0, target = 0;
    std::cin >> numOfElemToPush >> numOfElemToPop >> target;

    std::stack<int> stack = getInputStack(numOfElemToPush);

    popNElementsFromStack(stack, numOfElemToPop);

    findTarget(stack, target);

    return 0;
}
