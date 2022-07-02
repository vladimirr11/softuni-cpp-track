#include <iostream>

int** getMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }

    return matrix;
}

int main() {
    int rows {}, cols {};
    std::cin >> rows >> cols;

    int** matrix = getMatrix(rows, cols);

    int subRows {}, subCols {};
    std::cin >> subRows >> subCols;

    for (int i = 0; i < subRows; i++) {
        for (int j = 0; j < subCols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}
