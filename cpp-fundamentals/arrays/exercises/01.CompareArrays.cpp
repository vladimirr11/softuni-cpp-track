#include <iostream>
#include <array>

const int maxSize = 1000;

bool compareArrays(const std::array<int, maxSize>& arr1, int length1,
                   const std::array<int, maxSize>& arr2, int length2) {
    
    if (length1 != length2) {
        return false;
    }

    for (int i; i < length2; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}


std::array<int, maxSize> readInput(int& arrSize) {

    std::array<int, maxSize> array{};

    std::cin >> arrSize;

    for (int i = 0; i < arrSize; i++) {
        std::cin >> array[i];
    }

    return array;
}


int main() {

    int arrOneSize = 0;
    const std::array<int, maxSize> arrOne = readInput(arrOneSize);
    int arrTwoSize = 0;
    const std::array<int, maxSize> arrTwo = readInput(arrTwoSize);

    const bool equal = compareArrays(arrOne, arrOneSize, arrTwo, arrTwoSize);

    if (equal) {
        std::cout << "equal" << std::endl;
    } else {
        std::cout << "not equal" << std::endl;
    }

    return 0;
}