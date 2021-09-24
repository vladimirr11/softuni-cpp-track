#include <iostream>
#include <string>
#include <stack>

std::string getInputExpression() {
    std::string parenthesisSeq;
    getline(std::cin, parenthesisSeq);

    return parenthesisSeq;
}

int main() {
    std::string parenthesis = getInputExpression();

    std::stack<char> parenthesisStack;

    bool correctParenthesis = true;

    for (char ch : parenthesis) {
        if (parenthesisStack.empty() && (ch == ')' || ch == ']' || ch == '}')){
            correctParenthesis = false;
            break;
        }
        
        if (ch == '(' || ch == '[' || ch == '{') {
            parenthesisStack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            char topOfStack = parenthesisStack.top();
            parenthesisStack.pop();
            if (topOfStack == '(' && ch == ')') {
                continue;
            } else if (topOfStack == '[' && ch == ']') {
                continue; 
            } else if (topOfStack == '{' && ch == '}') {
                continue;
            } else {
                correctParenthesis = false;
                break;
            }
        }
    }

    if (parenthesisStack.empty() && correctParenthesis) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
