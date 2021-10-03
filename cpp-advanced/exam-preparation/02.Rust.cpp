#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>

const int arrSize = 10;

std::array<std::array<char, arrSize>, arrSize> readInput() {
    std::array<std::array<char, arrSize>, arrSize> charsArr {};

    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            std::cin >> charsArr[i][j];
        }
    }

    return charsArr;
}

std::vector<std::pair<int, int>> extractNewRustPositions(std::array<std::array<char, arrSize>, arrSize>& rustedArr) {

    std::vector<std::pair<int, int>> rustPositions {};

    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if (rustedArr[i][j] == '!') {
                    if (j + 1 < arrSize && rustedArr[i][j + 1] != '#') {
                        rustPositions.push_back(std::make_pair(i, j + 1));
                    }
                    if (j - 1 >= 0 && rustedArr[i][j - 1] != '#') {
                        rustPositions.push_back(std::make_pair(i, j - 1));
                    }
                    if (i + 1 < arrSize && rustedArr[i + 1][j] != '#') {
                        rustPositions.push_back(std::make_pair(i + 1, j));
                    } 
                    if (i - 1 >= 0 && rustedArr[i - 1][j] != '#') {
                        rustPositions.push_back(std::make_pair(i - 1, j));
                }
            }
        }
    }

    return rustPositions;
}

void spreadRust(std::array<std::array<char, arrSize>, arrSize>& rustedArr, int numMoves) {

    for (int i = 0; i < numMoves; i++) {
        std::vector<std::pair<int, int>> rustedPositions = extractNewRustPositions(rustedArr);
        for (auto pos : rustedPositions) {
            rustedArr[pos.first][pos.second] = '!';
        }
    }
}

void printResult(std::array<std::array<char, arrSize>, arrSize>& rustedArr) {
    for (auto arr : rustedArr) {
        for (auto ch : arr) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::array<std::array<char, arrSize>, arrSize> charsArr = readInput();

    int numMoves = 0;
    std::cin >> numMoves;

    spreadRust(charsArr, numMoves);

    printResult(charsArr);

    return 0;
}
