#include <iostream>

char** readInputMatrix(int rows) {
    char** inputMatrix = new char*[rows];
    for (int i = 0; i < rows; i++) {
        inputMatrix[i] = new char[rows];
        for (int j = 0; j < rows; j++) {
            std::cin >> inputMatrix[i][j];
        }
    }

    return inputMatrix;
}

int main() {
    int matrixDimens {};
    std::cin >> matrixDimens;

    char** matrix = readInputMatrix(matrixDimens);

    char targetSymbol {};
    std::cin >> targetSymbol;

    bool isTargetFound = false;
    for (int i = 0; i < matrixDimens; i++) {
        for (int j = 0; j < matrixDimens; j++) {
            if (matrix[i][j] == targetSymbol) {
                isTargetFound = true;
                std::cout << "(" << i << ", " << j << ")" << std::endl;
                break;
            }
        }
    }

    if (!isTargetFound) {
        std::cout << targetSymbol << " does not occur in the matrix" << std::endl;
    }

    for (int i = 0; i < matrixDimens; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}
