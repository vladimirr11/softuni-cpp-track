#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<char> get1DVecFromInput() {
    std::vector<char> vec1D;

    std::string iline;
    getline(std::cin, iline);
    std::istringstream istream(iline);

    char currChar;
    while (istream >> currChar) {
        vec1D.push_back(currChar);
    }

    return vec1D;
}

std::vector<std::vector<char>> getInputMatrix(int numRows) {
    std::vector<std::vector<char>> inputMatrix(numRows);
    for (auto& vec1D : inputMatrix) {
        vec1D = get1DVecFromInput();
    }

    return inputMatrix;
}

int findOutCountOf2x2SubmatricesInMatrix(const std::vector<std::vector<char>>& matrix, int rows, int cols) {
    int num2x2SubMatrices = 0;

    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < cols - 1; j++) {
            if (matrix[i][j] == matrix[i + 1][j] && 
                matrix[i][j] == matrix[i][j + 1] && 
                matrix[i][j] == matrix[i + 1][j + 1]) {
                num2x2SubMatrices++;
            }
        }
    }

    return num2x2SubMatrices;
}

int main() {
    int numRows = 0;
    int numCols = 0;
    std::cin >> numRows >> numCols;
    std::cin.ignore();

    const std::vector<std::vector<char>> matrix = getInputMatrix(numRows);

    int num2x2Submatrices = findOutCountOf2x2SubmatricesInMatrix(matrix, numRows, numCols);

    std::cout << num2x2Submatrices << std::endl;

    return 0;
}
