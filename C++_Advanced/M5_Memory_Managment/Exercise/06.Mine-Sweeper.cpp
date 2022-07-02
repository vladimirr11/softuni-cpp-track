#include <iostream>

char** getInputMatrix(int rows, int cols) {
    char** matrix = new char*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new char[cols];
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }

    return matrix;
}

void zeroInitializeIntMatrix(int** intMatrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        intMatrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            intMatrix[i][j] = 0;
        }
    }
}

bool isValidPos(int currRow, int currCol, int rows, int cols) {
    if (currRow >= 0 && currRow < rows && currCol >= 0 && currCol < cols) {
        return true;
    }
    return false;
}

void mineCell(int** matrix, int row, int col) {
    matrix[row][col]++;
}

void setMineAtPosition(int** matrix, int row, int col, int rows, int cols) {
    if (isValidPos(row, col, rows, cols)) {
        mineCell(matrix, row, col);
    }
}

void mineField(char** charMatrix, int** intMatrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (charMatrix[i][j] == '!') {
                setMineAtPosition(intMatrix, i, j, rows, cols);
                setMineAtPosition(intMatrix, i - 1, j, rows, cols);
                setMineAtPosition(intMatrix, i, j - 1, rows, cols);
                setMineAtPosition(intMatrix, i - 1, j - 1, rows, cols);
                setMineAtPosition(intMatrix, i + 1, j, rows, cols);
                setMineAtPosition(intMatrix, i, j + 1, rows, cols);
                setMineAtPosition(intMatrix, i + 1, j + 1, rows, cols);
                setMineAtPosition(intMatrix, i - 1, j + 1, rows, cols);
                setMineAtPosition(intMatrix, i + 1, j - 1, rows, cols);
            }
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<typename T>
void deleteMatrix(T** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    
    delete[] matrix;
}

int main() {
    int rows {}, cols {};
    std::cin >> rows >> cols;
    std::cin.ignore();

    char** charMatrix = getInputMatrix(rows, cols);

    int** intMatrix = new int*[rows];
    zeroInitializeIntMatrix(intMatrix, rows, cols);

    mineField(charMatrix, intMatrix, rows, cols);

    printMatrix(intMatrix, rows, cols);

    // deallocate memory
    deleteMatrix(charMatrix, rows, cols);
    deleteMatrix(intMatrix, rows, cols);

    return 0;
}
