#include <iostream>

int** readInputMatrix(int rows, int cols) {
    int** inputMatrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        inputMatrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            std::cin >> inputMatrix[i][j];
        }
    }

    return inputMatrix;
}

int* findSumOfMatrixDiagonals(int** matrix, int rows, int cols) {
    int* sumCols = new int[cols]{};
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            sumCols[j] += matrix[i][j];
        }
    }

    return sumCols;
}

int main() {
    int rows {}, cols {};
    std::cin >> rows >> cols;

    int** matrix = readInputMatrix(rows, cols);

    int* sumCols = findSumOfMatrixDiagonals(matrix, rows, cols);

    for (int i = 0; i < cols; i++) {
        std::cout << sumCols[i] << std::endl;
    }

    return 0;
}
