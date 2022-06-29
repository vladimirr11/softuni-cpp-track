#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

std::vector<std::vector<int>> get2DVecFromInput() {
    int numRows = 0;
    std::cin >> numRows;
    std::cin.ignore();

    std::vector<std::vector<int>> vec2D(numRows);

    for (std::vector<int>& vec1D : vec2D) {
        vec1D = get1DVecFromInput();
    }

    return vec2D;
}

std::vector<std::vector<std::vector<int>>> get3DVecFromInput(int size) {
    std::vector<std::vector<std::vector<int>>> vec3D(size);

    for (auto& vec2D : vec3D) {
        vec2D = get2DVecFromInput();
    }

    return vec3D;
}

void printResult (bool areVecsEqual) {
    std::cout << (areVecsEqual ? "equal" : "not equal") << std::endl;
}

int main() {
    const auto numOfVecs = 2;
    const auto vec3D = get3DVecFromInput(numOfVecs);
    
    const auto areVecsEqual = vec3D[0] == vec3D[1];

    printResult(areVecsEqual);

    return 0;
}
