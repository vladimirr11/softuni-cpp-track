#include <iostream>
#include <string>
#include <stack>

std::string getInputExpression() {
    std::string parenthesisSeq;
    getline(std::cin, parenthesisSeq);
    return parenthesisSeq;
}

bool findIfParenthesisCorrect(const std::string& parenthesis) {
    std::stack<char> parenthesisStack;

    for (char ch : parenthesis) {
        if (parenthesisStack.empty() && (ch == ')' || ch == ']' || ch == '}')){
            return false;
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
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::string parenthesis = getInputExpression();

    bool isParCorrect = findIfParenthesisCorrect(parenthesis);
    
    if (isParCorrect) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
