#include <iostream>
#include <array>
#include <cstdlib>

const int maxSize = 1000;

std::array<int, maxSize> readInput(int& arraySize) {
    std::cin >> arraySize;

    std::array<int, maxSize> array {};
    for (int i = 0; i < arraySize; i++) {
        std::cin >> array[i];
    }

    return array;
}

void findClosestNumbers(const std::array<int, maxSize>& arr, int arrSize, 
                        int& firstNumber, int& secondNumber) {

    int closestNumbersDifference = INT16_MAX;

    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if (abs(arr[i] - arr[j]) == 0) {
                continue;
            }
            if (abs(arr[i] - arr[j]) < closestNumbersDifference) {
                closestNumbersDifference = abs(arr[i] - arr[j]);
                firstNumber = arr[i];
                secondNumber = arr[j];
            }
        }
    }
}

int main() {
    int arrSize = 0;

    std::array<int, maxSize> arr = readInput(arrSize);

    int numOne = arr[0];
    int numTwo = arr[0];

    findClosestNumbers(arr, arrSize, numOne, numTwo);

    std::cout << abs(numOne - numTwo) << std::endl;

    return 0;   
}
