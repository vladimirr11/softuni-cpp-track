#include <iostream>
#include <array>
#include <string>
#include <sstream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;
using belowDiagonalsNums = std::vector<int>;

Matrix readMatrix() {
    int dim {};
    std::cin >> dim;
    std::cin.ignore();

    Matrix matrix(dim, std::vector<int>(dim));
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            std::cin >> matrix[i][j];
        }
    }

    return matrix;
}

int findPrimeNumSum(const belowDiagonalsNums& numArr) {
    int sumPrimeNums {};
    for (int i = 0; i < numArr.size(); i++) {
        int mid = numArr[i] / 2;
        bool isPrime = true;
        for (int j = 2; j <= mid; j++) {
            if (numArr[i] % j == 0) {
                isPrime = false;
            }
        }

        if (isPrime) {
            sumPrimeNums += numArr[i];
        }
    }

    return sumPrimeNums;
}

belowDiagonalsNums findNumbersBelowDiag(const Matrix& matrix) {
    belowDiagonalsNums numArr;
    size_t dimens = matrix.size();

    for (int i = 0; i < dimens; i++) {
        for (int j = 0; j < dimens; j++) {
            if (i > j && j > dimens - i - 1) {
                numArr.push_back(matrix[i][j]);
            }
        }
    }

    return numArr;
}
 
int main() {
    Matrix matrix = readMatrix();

    belowDiagonalsNums numArr = findNumbersBelowDiag(matrix);

    int sumPrimeNums = findPrimeNumSum(numArr);

    std::cout << sumPrimeNums << std::endl;

    return 0;
}
