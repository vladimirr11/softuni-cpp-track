#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

std::string getInputString() {
    std::string str;
    getline(std::cin, str);
    return str;
}

int findSnakePart(int& currSnakePart, int snakeSize) {
    if (currSnakePart + 1 < snakeSize) {
        currSnakePart++;
    } else {
        currSnakePart = 0;
    }

    return currSnakePart;
}

std::vector<std::vector<char>> fillSnakeMoves(std::string& snakeStr, int rows, int cols) {
    std::vector<std::vector<char>> snakeMovesMatrix(rows, std::vector<char>(cols, '#'));

    const int snakeSize = snakeStr.size();

    int currSnakePart = -1;
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; j++) {
                snakeMovesMatrix[i][j] = snakeStr[findSnakePart(currSnakePart, snakeSize)];
            } 
        } else {
            for (int j = cols - 1; j >= 0; j--) {
                snakeMovesMatrix[i][j] = snakeStr[findSnakePart(currSnakePart, snakeSize)];
            } 
        }
    }

    return snakeMovesMatrix;
}

void printRow(std::vector<char>& row) {
    for (const char c : row) {
        std::cout << c;
    }
    std::cout << std::endl;
}

void printSnakeMoves(std::vector<std::vector<char>>& snakeMovesMatrix) {
    std::for_each(snakeMovesMatrix.begin(), snakeMovesMatrix.end(), [](std::vector<char>& row) -> void {
        printRow(row);
    });
}

int main() {
    int numRows = 0;
    int numCols = 0;
    std::cin >> numRows >> numCols;
    std::cin.ignore();

    std::string snakeString = getInputString();

    std::vector<std::vector<char>> snakeMovesMatrix = fillSnakeMoves(snakeString, numRows, numCols);

    printSnakeMoves(snakeMovesMatrix);

    return 0;
}
