#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

using Matrix = std::vector<std::vector<char>>;

Matrix readInputMatrix(int numRows, int numCols) {
    Matrix matrix(numRows, std::vector<char>(numCols));
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cin >> matrix[i][j];
        }
    }

    return matrix;
}

bool isInBoundary(const Matrix& matrix, int currX, int currY) {
    if (0 > currX) return false;
    if (0 > currY) return false;
    if (currX >= static_cast<int>(matrix.size())) return false;
    if (currY >= static_cast<int>(matrix[0].size())) return false;

    return true;
}

void DFS(Matrix& matrix, const char allowedChar, const char fillChar, int currRow, int currCol) {
    const bool isInMatrix = isInBoundary(matrix, currRow, currCol);
    if (!isInMatrix) {
        return;
    }

    if (matrix[currRow][currCol] != allowedChar) {
        return;
    }

    matrix[currRow][currCol] = fillChar;

    DFS(matrix, allowedChar, fillChar, currRow, currCol + 1); // go right
    DFS(matrix, allowedChar, fillChar, currRow + 1, currCol); // go down
    DFS(matrix, allowedChar, fillChar, currRow, currCol - 1); // go left
    DFS(matrix, allowedChar, fillChar, currRow - 1, currCol); // go up

}

void printSolution(Matrix& matrix) {
    for (auto vec : matrix) {
        for (auto ch : vec) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
}

int main() {
    int numRows, numCols, modulo;
    std::cin >> numRows >> numCols;

    Matrix matrix = readInputMatrix(numRows, numCols);

    char fillChar;
    std::cin >> fillChar;

    int startRow, startCol;
    std::cin >> startRow >> startCol;

    char allowedChar = matrix[startRow][startCol];

    DFS(matrix, allowedChar, fillChar, startRow, startCol);
    printSolution(matrix);

    return 0;
}
