#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::string getBrackets() {
    std::string brackets;
    std::cin >> brackets;

    return brackets;
}

bool verifyBracketsCorrectness(std::string& brackets) {

    std::vector<char> openBracketsStack;

    bool validExpression = true;

    size_t bracketsLength = brackets.size();
    for (size_t i = 0; i < bracketsLength; i++) {
        if (brackets[i] == '{') {
            openBracketsStack.push_back(brackets[i]);
        } else if (brackets[i] == '[') { 
            if (brackets[i + 1] == '{') {
                validExpression = false;
                return validExpression;
            } else {
                openBracketsStack.push_back(brackets[i]);
            }
        } else if (brackets[i] == '(') {
            if (brackets[i + 1] == '{' || brackets[i + 1] == '[') {
                validExpression = false;
                return validExpression;
            } else {
                openBracketsStack.push_back(brackets[i]);
            }
        } else if (brackets[i] == ']') {
            if (openBracketsStack.back() == '[') { 
                openBracketsStack.pop_back();
            } else {
                validExpression = false;
                return validExpression;
            }
        } else if (brackets[i] == ')') {
            if (openBracketsStack.back() == '(') { 
                openBracketsStack.pop_back();
            } else {
                validExpression = false;
                return validExpression;
            }
        } else if (brackets[i] == '}') {
            if (openBracketsStack.back() == '{') { 
                openBracketsStack.pop_back();
            } else {
                validExpression = false;
                return validExpression;
            }
        }
    } 

    return validExpression;  
}

int main() {

    std::string brackets = getBrackets();

    bool areBracketsCorrect = verifyBracketsCorrectness(brackets);

    if (areBracketsCorrect) {
        std::cout << "valid" << std::endl;
    } else {
        std::cout << "invalid" << std::endl;
    }

    return 0;
}