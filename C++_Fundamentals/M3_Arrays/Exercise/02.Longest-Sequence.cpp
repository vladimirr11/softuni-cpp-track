#include <iostream>
#include <array>

const int maxSize = 1000;

std::array<int, maxSize> readInput(int& arrSize) {
    std::cin >> arrSize;
    
    std::array<int, maxSize> array {};
    for (int i = 0; i < arrSize; i++) {
        std::cin >> array[i];
    }

    return array;
}

void findLongestSequenceOfElements(const std::array<int, maxSize>& array, int arraySize, 
                                    int& consecutiveElement, int& biggestCounter) {
    int counterConsecutiveElements = 1;

    biggestCounter = 1;
    consecutiveElement = array[0];

    for (int i = 0; i < arraySize - 1; i++) {
        if (array[i] == array[i + 1]) {
            consecutiveElement = array[i];
            counterConsecutiveElements += 1;
            if (counterConsecutiveElements >= biggestCounter) {
                biggestCounter = counterConsecutiveElements;
            }
        } else {
            counterConsecutiveElements = 1;
        }
    }

    if (biggestCounter == 1) {
        consecutiveElement = array[arraySize - 1];
    }
}

void printResult(int consecutiveElement, int biggestCounter) {   
    for (int i = 0; i < biggestCounter; i++) {
        std::cout << consecutiveElement << " ";
    }
    std::cout << std::endl;
}

int main() {
    int consecutiveElement = 0;
    int biggestCounter = 0;

    int arraySize = 0;

    const std::array<int, maxSize> arr = readInput(arraySize);

    findLongestSequenceOfElements(arr, arraySize, consecutiveElement, biggestCounter);

    printResult(consecutiveElement, biggestCounter);

    return 0;
}
