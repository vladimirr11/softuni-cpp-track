#include <iostream>
#include <array>

const int maxArrSize = 1000;

std::array<int, maxArrSize> getInput(int& arrSize) {
    std::array<int, maxArrSize> array{};

    std::cin >> arrSize;

    for (int i = 0; i < arrSize; i++) {
        std::cin >> array[i];
    }

    return array;
}

double findAverageNumberOfArray(const std::array<int, maxArrSize>& arr, int& arrSize) {
    int sumArr = 0;
    for (int i = 0; i < arrSize; i++) {
        sumArr += arr[i];
    }

    double averageNum = sumArr / (double)arrSize;

    return averageNum;
}

int calculateSumOfElements(const std::array<int, maxArrSize>& arr, const int& arrSize, 
                            double& avergaeNum) {
    int sumEven = 0;
    int sumOdd = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] <= avergaeNum) {
            if (i % 2 == 0) {
            sumEven += arr[i];
            } else {
            sumOdd += arr[i];
            }
        }
    }

    int productEls = sumEven * sumOdd;

    return productEls;
}

int main() {
    int arrSize = 0;
    const std::array<int, maxArrSize> arr = getInput(arrSize);

    double averageNumber = findAverageNumberOfArray(arr, arrSize);

    int result = calculateSumOfElements(arr, arrSize, averageNumber);

    std::cout << result << std::endl;

    return 0;
}
