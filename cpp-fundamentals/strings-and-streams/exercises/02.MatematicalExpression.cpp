#include <iostream>
#include <array>
#include <string>
#include <sstream>

std::string getInputString() {
    std::string line;
    getline(std::cin, line);
    return line;
}

void verifyIfMathExpressionIsCorrect(std::string mathExpression) {

    int countOpenBrackets = 0;
    int countCloseBrackets = 0;

    for (int i = 0; i < mathExpression.size(); i++) {
        if (mathExpression[i] == '(') {
            countOpenBrackets++;
        } else if (mathExpression[i] == ')') {
            countCloseBrackets++;
        }
    }

    if (countOpenBrackets != countCloseBrackets) {
        std::cout << "incorrect" << std::endl;
    } else {
        std::cout << "correct" << std::endl;
    }

}

int main() {

    std::string mathExpression = getInputString();

    verifyIfMathExpressionIsCorrect(mathExpression);

    return 0;
}