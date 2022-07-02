#include <iostream>
#include <string>
#include <sstream>

const int MAX_LEN_DIMENS = 10;

int** getInputMatrix(int& rows, int& colSize) {
    std::cin >> rows;
    std::cin.ignore();

    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[MAX_LEN_DIMENS];
        std::string iline;
        std::getline(std::cin >> std::ws, iline);
        std::istringstream istr(iline);

        // set colSize = 0;
        colSize = 0;
        int currNum {};
        while (istr >> currNum) {
            matrix[i][colSize] = currNum;
            colSize++;
        }
    }

    return matrix;
}

bool compareMatrices(int** matrixA, int** matrixB, int rows, int cols) {
    for (int** api = &matrixA[0], **bpi = &matrixB[0]; api != &matrixA[rows]; api++, bpi++) {
        for (int* apj = *api, *bpj = *bpi; apj != *api + cols; apj++, bpj++) {
            if (*apj != *bpj) {
                return false;
            }
        }
    }

    return true;
}

template<typename T>
void deleteMatrix(T** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int main() {
    int rowsMatrixA {}, colSizeMatrixA {};
    int** matrixA = getInputMatrix(rowsMatrixA, colSizeMatrixA);

    int rowsMatrixB {}, colSizeMatrixB {};
    int** matrixB = getInputMatrix(rowsMatrixB, colSizeMatrixB);

    if (rowsMatrixA != rowsMatrixB || colSizeMatrixA != colSizeMatrixB) {
        std::cout << "not equal" << std::endl;
    } else {
        bool areMatricesEqual = compareMatrices(matrixA, matrixB, rowsMatrixA, colSizeMatrixA);
        if (areMatricesEqual) {
            std::cout << "equal" << std::endl;
        } else {
            std::cout << "not equal" << std::endl;
        }
    }

    // deallocate memory
    deleteMatrix(matrixA, rowsMatrixA, colSizeMatrixA);
    deleteMatrix(matrixB, rowsMatrixB, colSizeMatrixB);

    return 0;
}
