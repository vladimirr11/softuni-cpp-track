#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>
#include <unordered_map>

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

std::unordered_map<char, std::deque<std::pair<int, int>>> findGlitchesPositions(
                        std::vector<std::vector<char>>& matrix, 
                        const int dimensMatrix) {
    
    std::unordered_map<char, std::deque<std::pair<int, int>>> glitchesPositionMap {};

    for (int i = 0; i < dimensMatrix; i++) {
        for (int j = 0; j < dimensMatrix; j++) {
            if (matrix[i][j] != '.') {
                char currGlitch = matrix[i][j];
                glitchesPositionMap[currGlitch].push_back(std::make_pair(i, j));
            }
        }
    }

    return glitchesPositionMap;
}

std::unordered_map<char, std::pair<int, int>> findGlitchesCenters(
                        std::unordered_map<char, std::deque<std::pair<int, int>>>& glitchesPositionMap) {
    
    std::unordered_map<char, std::pair<int, int>> glitchesCenters {};

    for (auto glitch : glitchesPositionMap) {

        auto firstPair = glitch.second.front();
        int firstRow = firstPair.first;
        int firstCol = firstPair.second;

        auto lastPair = glitch.second.back();
        int lastRow = lastPair.first;
        int lastCol = lastPair.second;

        int rowCenter = (lastRow - firstRow) / 2 + firstRow;

        glitchesCenters[glitch.first] = std::make_pair(rowCenter, firstCol);
    }

    return glitchesCenters;
}

void printSolution(std::vector<std::vector<char>>& matrix, const int dimensMatrix, 
                    std::unordered_map<char, std::pair<int, int>>& glitchesCenters) {

    std::vector<std::vector<char>> matrixToPrint(dimensMatrix, std::vector<char> (dimensMatrix, '.'));
    for (auto pair : glitchesCenters) {
        for (int i = 0; i < dimensMatrix; i++) {
            for (int j = 0; j < dimensMatrix; j++) {
                if (i == pair.second.first && j == pair.second.second) {
                    matrixToPrint[i][j] = pair.first;
                } 
            }
        }   
    }

    for (auto vec : matrixToPrint) {
        for (auto el : vec) {
            std::cout << el;
        }
        std::cout << std::endl;
    }

}

int main() {
    int dimensMatrix = 0;
    std::cin >> dimensMatrix;
    std::cin.ignore();

    std::vector<std::vector<char>> matrix = getInputMatrix(dimensMatrix);

    auto glitchesPosMap = findGlitchesPositions(matrix, dimensMatrix);

    auto glitchesCenters = findGlitchesCenters(glitchesPosMap);

    printSolution(matrix, dimensMatrix, glitchesCenters);

    return 0;
}
