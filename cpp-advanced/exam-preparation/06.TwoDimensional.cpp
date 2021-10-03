#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

std::vector<std::vector<char>> readInputMatrix(int numRows, int numCols) {

    std::vector<std::vector<char>> matrix {};

    matrix.resize(numRows);

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            char currChar;
            std::cin >> currChar;
            matrix[i].push_back(currChar);
        }
    }

    return matrix;
}

bool isInBoundary(const std::vector<std::vector<char>>& matrix, int currX, int currY) {
    if (0 > currX) return false;
    if (0 > currY) return false;
    if (currX >= int(matrix.size())) return false;
    if (currY >= int(matrix[0].size())) return false;

    return true;
}

void DFS(std::vector<std::vector<char>>& matrix, const char allowedChar, 
                            const char fillChar, int currRow, int currCol) {
    
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

void printSolution(std::vector<std::vector<char>>& matrix) {
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

    std::vector<std::vector<char>> matrix = readInputMatrix(numRows, numCols);

    char fillChar;
    std::cin >> fillChar;

    int startRow, startCol;
    std::cin >> startRow >> startCol;

    char allowedChar = matrix[startRow][startCol];

    DFS(matrix, allowedChar, fillChar, startRow, startCol);
    printSolution(matrix);

    return 0;
}
