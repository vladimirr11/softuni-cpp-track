#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int getNumberOfPipes() {
    int numOfPipes = 0;
    std::cin >> numOfPipes;
    std::cin.ignore();
    return numOfPipes;
}

std::vector<int> getInputPipes() {
    std::vector<int> vec;

    std::string line;
    getline(std::cin, line);
    std::istringstream stream(line);

    int currentNumber = 0;
    while(stream >> currentNumber) {
        vec.push_back(currentNumber);
    }

    return vec;
}

void calculateLifespanOfPipes(std::vector<int>& initVec, std::vector<int>& checkupVec) {
    std::vector<int> lifespanVector;

    int rateDayaOfPipes = 0;

    size_t vecSize = initVec.size();
    for (size_t i = 0; i < vecSize; i++) {
        rateDayaOfPipes = initVec[i] - checkupVec[i];
        lifespanVector.push_back(initVec[i] / rateDayaOfPipes);
    }

    for (int el : lifespanVector) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

int main() {
    int numberOfPipes = getNumberOfPipes();

    std::vector<int> checkupVector = getInputPipes();
    std::vector<int> initVector = getInputPipes();

    calculateLifespanOfPipes(initVector, checkupVector);

    return 0;
}
