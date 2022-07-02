#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>

const int arrSize = 10;

using Matrix = std::array<std::array<char, arrSize>, arrSize>;

Matrix readInputMatrix() {
    Matrix charsMatrix {};
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            std::cin >> charsMatrix[i][j];
        }
    }

    return charsMatrix;
}

bool isValidPos(int currRow, int currCol) {
    if (currRow >= 0 && currRow < arrSize && currCol >= 0 && currCol < arrSize) {
        return true;
    }
    return false;
}

bool checkIfCellCanRust(const Matrix& matrix, int row, int col) {
    if (isValidPos(row, col) && matrix[row][col] != '#') {
        return true;
    }
    return false;
}

std::vector<std::pair<int, int>> extractNewRustPositions(const Matrix& charsMatrix) {
    std::vector<std::pair<int, int>> rustPositions {};

    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if (charsMatrix[i][j] == '!') {
                    if (checkIfCellCanRust(charsMatrix, i, j + 1)) {
                        rustPositions.push_back(std::make_pair(i, j + 1));
                    }
                    if (checkIfCellCanRust(charsMatrix, i, j - 1)) {
                        rustPositions.push_back(std::make_pair(i, j - 1));
                    }
                    if (checkIfCellCanRust(charsMatrix, i + 1, j)) {
                        rustPositions.push_back(std::make_pair(i + 1, j));
                    } 
                    if (checkIfCellCanRust(charsMatrix, i - 1, j + 1)) {
                        rustPositions.push_back(std::make_pair(i - 1, j));
                }
            }
        }
    }

    return rustPositions;
}

void spreadRust(Matrix& charsMatrix, int numMoves) {
    for (int i = 0; i < numMoves; i++) {
        std::vector<std::pair<int, int>> posToRust = extractNewRustPositions(charsMatrix);
        for (auto pos : posToRust) {
            charsMatrix[pos.first][pos.second] = '!';
        }
    }
}

void printResult(const Matrix& rustedMatrix) {
    for (auto arr : rustedMatrix) {
        for (auto ch : arr) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
}

int main() {
    Matrix charsMatrix = readInputMatrix();

    int numMoves = 0;
    std::cin >> numMoves;

    spreadRust(charsMatrix, numMoves);

    printResult(charsMatrix);

    return 0;
}
