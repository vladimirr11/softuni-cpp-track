#include <iostream>
#include <stack>
#include <string>
#include <sstream>

std::stack<int> getInputClothesStack() {
    std::stack<int> stack;

    std::string iline;
    getline(std::cin, iline);
    std::istringstream istream(iline);

    int currNum = 0;
    while (istream >> currNum) {
        stack.push(currNum);
    }

    return stack;
}

void workOutNeededRacks(std::stack<int>& clothesStack, int rackCapacity) {
    int clothesWeight = 0;

    int numOfRacks = 1;
    while (!clothesStack.empty()) {
        int currClothing = clothesStack.top();
        if (rackCapacity >= (clothesWeight + currClothing)) {
            clothesWeight += currClothing;
            clothesStack.pop();
        } else {
            numOfRacks++;
            clothesWeight = 0;
            clothesWeight += currClothing;
            clothesStack.pop();
        }
    }

    std::cout << numOfRacks << std::endl;
}

int main() {
    std::stack<int> clothesStack = getInputClothesStack();

    int rackCapacity = 0;
    std::cin >> rackCapacity;

    workOutNeededRacks(clothesStack, rackCapacity);

    return 0;
}
