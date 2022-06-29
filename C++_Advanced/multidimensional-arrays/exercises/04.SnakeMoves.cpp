#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::string getInputString() {
    std::string str;
    getline(std::cin, str);

    return str;
}

std::vector<std::vector<char>> fillSnakeMoves(std::string& snakeStr, int rows, int cols) {

    std::vector<std::vector<char>> snakeMovesMatrix(rows, std::vector<char>(cols, 'a'));

    const int snakeSize = snakeStr.size();

    int currSnakePart = 0;
    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < cols; j++) {
                snakeMovesMatrix[i][j] = snakeStr[currSnakePart];

                if (currSnakePart + 1 < snakeSize) {
                    currSnakePart++;
                } else {
                    currSnakePart = 0;
                }
            } 
        } else {
            for (int j = cols - 1; j >= 0; j--) {
                snakeMovesMatrix[i][j] = snakeStr[currSnakePart];

                if (currSnakePart + 1 < snakeSize) {
                    currSnakePart++;
                } else {
                    currSnakePart = 0;
                }
            } 
        }
    }

    return snakeMovesMatrix;
}

void printSnakeMoves(std::vector<std::vector<char>>& snakeMovesMatrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << snakeMovesMatrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int numRows = 0;
    int numCols = 0;
    std::cin >> numRows >> numCols;
    std::cin.ignore();

    std::string snakeString = getInputString();

    std::vector<std::vector<char>> snakeMovesMatrix = fillSnakeMoves(snakeString, numRows, numCols);

    printSnakeMoves(snakeMovesMatrix, numRows, numCols);

    return 0;
}
