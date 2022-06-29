#include <iostream>
#include <string>
#include <sstream>
#include <stack>

std::stack<int> getInputStack() {
    std::stack<int> stack;

    std::string line;
    getline(std::cin, line);
    std::istringstream stream(line);

    int currNumber;
    while (stream >> currNumber) {
        stack.push(currNumber);
    }

    return stack;
}

void performOperationsWhitStack(std::stack<int>& stack) {
    bool flag = false;

    while (true) {
        if (flag == true) {
            break;
        }

        std::string line;
        getline(std::cin, line);
        std::istringstream stream(line);

        std::string command;
        while (!stream.eof()) {
            stream >> command;
            if (command == "end") {
                flag = true;
                break;
            } else if (command == "add") {
                int intOne = 0;
                int intTwo = 0;
                stream >> intOne >> intTwo;
                stack.push(intOne);
                stack.push(intTwo);
            } else if (command == "remove") {
                int numToRemove = 0;
                stream >> numToRemove;

                if (numToRemove > stack.size()) {
                    continue;
                }

                for (int i = 0; i < numToRemove; i++) {
                    stack.pop();
                }
            }
        }
    }
}

int main() {
    std::stack<int> stack = getInputStack();

    performOperationsWhitStack(stack);

    int sumOfStack = 0;
    while(!stack.empty()) {
        sumOfStack += stack.top();
        stack.pop();
    }

    std::cout << "Sum: " << sumOfStack << std::endl;

    return 0;
}
