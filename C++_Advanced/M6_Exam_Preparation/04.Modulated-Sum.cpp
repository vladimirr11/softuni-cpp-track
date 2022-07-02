#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <array>

std::vector<std::vector<int>> readInputMatrix(int numRows, int numCols) {
    std::vector<std::vector<int>> matrix(numRows, std::vector<int>(numCols));
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cin >> matrix[i][j];
        }
    }

    return matrix;
}

void sumElOfMatrixByColumnAndDevideByModulo(const std::vector<std::vector<int>>& matrix, 
                                            const int numRows, const int numCols, const int modulo) {
    for (int colIdx = 0; colIdx < numCols; colIdx++) {
        int sumColEls = 0;
        for (int rowIdx = 0; rowIdx < numRows; rowIdx++) {
            sumColEls += matrix[rowIdx][colIdx];
        }
        int moduloReminder = sumColEls % modulo;
        std::cout << moduloReminder << " ";
    }
    std::cout << std::endl;   
}

int main() {
    int numRows, numCols, modulo;
    std::cin >> numRows >> numCols;
    std::cin.ignore();

    std::vector<std::vector<int>> matrix = readInputMatrix(numRows, numCols);

    std::cin >> modulo;

    sumElOfMatrixByColumnAndDevideByModulo(matrix, numRows, numCols, modulo);   

    return 0;
}
