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


void calculateAverage(const std::array<int, maxSize>& arr, int arrSize, float& mean) {

    int sumNumbers = 0;
    mean = 0;

    for (int i = 0; i < arrSize; i++) {
        sumNumbers += arr[i];
    }

    mean = sumNumbers / arrSize;

}


void printResult(const std::array<int, maxSize>& arr, int arrSize, float& mean) {

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] >= mean) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;

}


int main() {

    int arrSize = 0;
    float mean = 0;

    std::array<int, maxSize> arr = readInput(arrSize);

    calculateAverage(arr, arrSize, mean);

    printResult(arr, arrSize, mean);

}