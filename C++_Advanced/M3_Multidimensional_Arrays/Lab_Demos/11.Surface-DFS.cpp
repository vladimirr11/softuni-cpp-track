#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stack>

std::vector<std::vector<char>> readMatrixFromInput() {
    int width = 0;
    int height = 0;
    std::cin >> width >>height;

    std::vector<std::vector<char>> matrix(height, std::vector<char>(width));
    for (auto& row : matrix) {
        for (auto& elem : row) {
            std::cin >> elem;
        }
    }

    return matrix;
}

std::vector<std::pair<int, int>> readCommandsFromInput() {
    int commandSize = 0;
    std::cin >> commandSize;

    std::vector<std::pair<int, int>> commands;
    for (auto& pair : commands) {
        std::cin >> pair.first >> pair.second;
    }

    return commands;
}

bool isInBoundary(const std::vector<std::vector<char>>& matrix, int currX, int currY) {
    if (0 > currX) return false;
    if (0 > currY) return false;
    if (currY >= int(matrix.size())) return false;
    if (currX >= int(matrix[0].size())) return false;

    return true;
}

void DFS(int cuurX, int currY, std::vector<std::vector<char>>& matrix,
                    std::stack<std::pair<int, int>>& futureCoordinates,
                    int& currLakeSize) {
    const bool isInside = isInBoundary(matrix, cuurX, currY);
    if (!isInside) {
        return;
    }
    
    const char landMark = '#';
    if (matrix[cuurX][currY] == landMark) {
        return;
    }

    currLakeSize++;
    matrix[currY][cuurX] = landMark;

    futureCoordinates.push(std::make_pair(cuurX + 1, currY));   // go right
    futureCoordinates.push(std::make_pair(cuurX, currY + 1));   // go down 
    futureCoordinates.push(std::make_pair(cuurX - 1, currY));   // go left
    futureCoordinates.push(std::make_pair(cuurX, currY - 1));   // go up

}

std::vector<int> executeCommands(const std::vector<std::vector<char>>& matrix,
                                 const std::vector<std::pair<int, int>>& commands) {
    std::vector<int> results;
    results.reserve(commands.size());

    int currLakeSize = 0;
    std::vector<std::vector<char>> matrixCopy = matrix;
    std::stack<std::pair<int, int>> futureCoordinates;
    std::pair<int, int> currCoord;

    for (const auto& pair : commands) {
        // reset
        currLakeSize = 0;
        matrixCopy = matrix;
        futureCoordinates.push(pair);
        while (!futureCoordinates.empty()) {
            currCoord = futureCoordinates.top();
            futureCoordinates.pop();

            // process
            DFS(currCoord.first, currCoord.second, matrixCopy, futureCoordinates, currLakeSize);
        }

        // push result
        results.push_back(currLakeSize);
    }

    return results;
}

void printSolution(const std::vector<int>& results) {
    for (const int result : results) {
        std::cout << result << '\n';
    }
    std::cout << std::endl;
}

int main() {
    const auto matrix = readMatrixFromInput();
    const auto commands = readCommandsFromInput();
    const auto results = executeCommands(matrix, commands);

    printSolution(results);

    return 0;
}
