#include <iostream>
#include <string>
#include <sstream>
#include <stack>

std::string getInputExpression() {
    std::string expression;
    getline(std::cin, expression);
    return expression;
}

int main() {
    std::string expression = getInputExpression();

    std::stack<int> stack;
    for (size_t i = 0; i < expression.size(); i++) {
        if (expression[i] == '(') {
            stack.push(i);
        } else if (expression[i] == ')') {
            size_t startIdx = stack.top();
            std::string subExpression = expression.substr(startIdx, i - startIdx + 1);
            stack.pop();
            std::cout << subExpression << std::endl;
        }
    }

    return 0;
}
