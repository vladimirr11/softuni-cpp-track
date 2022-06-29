#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <bits/stdc++.h>

std::string getInputLine() {
    std::string line;
    getline(std::cin, line);
    return line;
}

int main() {
    std::string inputLine = getInputLine();
    std::istringstream stream(inputLine);
    std::stack<std::string> stack;

    std::string currWord;
    while (stream >> currWord) {
        stack.push(currWord);
    }

    while (!stack.empty()) {
        std::string currWordToReverse = stack.top();
        std::reverse(currWordToReverse.begin(), currWordToReverse.end());
        std::cout << currWordToReverse << ' ';
        stack.pop();
    }
    
    std::cout << std::endl;

    return 0;
}
