#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

std::vector<int> get1DVecFromInput() {
    std::vector<int> vec1D;

    std::string iline;
    getline(std::cin, iline);
    std::istringstream istream(iline);

    int currNumber = 0;
    while (istream >> currNumber) {
        vec1D.push_back(currNumber);
    }

    return vec1D;
}

std::vector<std::vector<int>> getInputMatrix(int numRows) {
    std::vector<std::vector<int>> inputMatrix(numRows);
    for (auto& vec1D : inputMatrix) {
        vec1D = get1DVecFromInput();
    }

    return inputMatrix;
}

std::vector<std::pair<int, int>> findCoordsOfElementInMatrix(const std::vector<std::vector<int>>& matrix,
                                                             int numRows, int numCols) {
    std::vector<std::pair<int, int>> coordsVec;

    int numToSearch = 0;
    std::cin >> numToSearch;
    std::cin.ignore();

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (matrix[i][j] == numToSearch) {
                coordsVec.push_back(std::make_pair(i, j));
            }
        }
    }

    return coordsVec;
}

void printResult(std::vector<std::pair<int, int>>& coordsVec) {
    if (coordsVec.size() == 0) {
        std::cout << "not found" << std::endl;
    } else {
        std::for_each(coordsVec.begin(), coordsVec.end(), [](std::pair<int, int>& p) {
            std::cout << p.first << " " << p.second << std::endl;
        });
    }
}

int main() {
    int numRows = 0;
    int numCols = 0;
    std::cin >> numRows >> numCols;
    std::cin.ignore();

    const std::vector<std::vector<int>> matrix = getInputMatrix(numRows);

    std::vector<std::pair<int, int>> coordsVec = findCoordsOfElementInMatrix(matrix, numRows, numCols);

    printResult(coordsVec);

    return 0;
}
