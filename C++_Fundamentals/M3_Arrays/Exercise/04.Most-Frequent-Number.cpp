#include <iostream>
#include <array>
#include <bits/stdc++.h>

const int maxSize = 1000;

std::array<int, maxSize> readInput(int& arraySize) {
    std::cin >> arraySize;

    std::array<int, maxSize> array {};
    for (int i = 0; i < arraySize; i++) {
        std::cin >> array[i];
    }

    return array;
}

void findMostFrequentElement(const std::array<int, maxSize>& arr, int arrSize, int& mostFrequentElement) {
    int currentCounter = 0;
    int mostFrequentElementCounter = 0;
    int currentMostFrequentElement = arr[0];

    std::array<int, 1000> supplArray {};
    int supplArraySize = 0;
    
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == currentMostFrequentElement) {
            currentCounter += 1;
            if (currentCounter > mostFrequentElementCounter) {
                supplArraySize = 0;
                mostFrequentElementCounter = currentCounter;
                currentMostFrequentElement = arr[i];
                mostFrequentElement = currentMostFrequentElement;
            } else if (currentCounter == mostFrequentElementCounter) {
                supplArray[supplArraySize] = arr[i];
                currentMostFrequentElement = arr[i];
                supplArraySize++;
            }
        } else {
            currentMostFrequentElement = arr[i];
            currentCounter = 0;
        }
    }

    std::stable_sort(supplArray[0], supplArray[supplArraySize]);

    for (int i = 0; i < supplArraySize; i++) {
        std::cout << supplArray[i] << std::endl;
    }
}

void printResult(int mostFrequentElement) {
    std::cout << mostFrequentElement << std::endl;
}

int main() {
    int mostFrequentElement = 0;
    int arrSize = 0;

    std::array<int, maxSize> arr = readInput(arrSize);

    findMostFrequentElement(arr, arrSize, mostFrequentElement);

    printResult(mostFrequentElement);
    
    return 0;
}
