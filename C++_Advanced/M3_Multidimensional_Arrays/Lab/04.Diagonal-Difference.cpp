#include <iostream>

int** readInputMatrix(int rows) {
    int** inputMatrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        inputMatrix[i] = new int[rows];
        for (int j = 0; j < rows; j++) {
            std::cin >> inputMatrix[i][j];
        }
    }

    return inputMatrix;
}

int findDiagonalDiff(int** matrix, int dimens) {
    int sumPrimaryDiag {};
    int sumSecondaryDiag {};
    for (int i = 0; i < dimens; i++) {
        sumPrimaryDiag += matrix[i][i];
        sumSecondaryDiag += matrix[i][dimens - i - 1];
    }

    int diagonaDiff {};
    if (sumPrimaryDiag > sumSecondaryDiag) {
        diagonaDiff = sumPrimaryDiag - sumSecondaryDiag;
    } else {
        diagonaDiff = sumSecondaryDiag - sumPrimaryDiag;
    }

    return diagonaDiff;
}

int main() {
    int matrixDimens {};
    std::cin >> matrixDimens;

    int** matrix = readInputMatrix(matrixDimens);

    int diagonalDiff = findDiagonalDiff(matrix, matrixDimens);

    std::cout << diagonalDiff << std::endl;

    return 0;
}
