#include <iostream>
#include <string>
#include <array>
#include <sstream>

const int maxSize = 1000;

std::array<int, maxSize> getInputAarray(int& arrSize) {
    arrSize = 0;
    std::array<int, maxSize> arr{};

    std::string line;
    getline(std::cin, line);

    std::istringstream stream(line);

    int currentNUmber = 0;
    while (stream >> currentNUmber) {
        arr[arrSize] = currentNUmber;
        arrSize++; 
    }
    
    return arr;
}

bool compareArrays(const std::array<int, maxSize>& arr1, int arrSize1,
                   const std::array<int, maxSize>& arr2, int arrSize2) {
    if (arrSize1 != arrSize2) {
        return false;
    }

    for (int i = 0; i < arrSize2; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}

int main() {

    int arrayOneSize = 0;
    std::array<int, maxSize> arrayOne = getInputAarray(arrayOneSize);

    int arrayTwoSize = 0;
    std::array<int, maxSize> arrayTwo = getInputAarray(arrayTwoSize);

    bool result = compareArrays(arrayOne, arrayOneSize, arrayTwo, arrayTwoSize);

    if (result) {
        std::cout << "equal" << std::endl;
    } else {
        std::cout << "not equal" << std::endl;
    }

    return 0;
}