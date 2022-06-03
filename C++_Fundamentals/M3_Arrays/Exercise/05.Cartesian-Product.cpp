#include <iostream>
#include <array>

const int maxSize = 1000;

std::array<int, maxSize> readInput(int& arraySize) {
    std::cin >> arraySize;

    std::array<int, maxSize> array {};
    for (int i = 0; i < arraySize; i++) {
        std::cin >> array[i];
    }

    return array;
}

int main() {
    int arrSize = 0;

    std::array<int, maxSize> arr = readInput(arrSize);

    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            std::cout << arr[i] * arr[j] << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}
