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
    for (int i = 0; i < dimens; i++) {
        sumPrimaryDiag += matrix[i][i];
    }

    return sumPrimaryDiag;
}

int main() {
    int matrixDimens {};
    std::cin >> matrixDimens;

    int** matrix = readInputMatrix(matrixDimens);

    int sumPrimaryDiag = findDiagonalDiff(matrix, matrixDimens);

    std::cout << sumPrimaryDiag << std::endl;

    return 0;
}
