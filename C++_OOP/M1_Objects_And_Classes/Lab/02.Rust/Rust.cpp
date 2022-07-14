#include "Rust.h"

void MetalField::read(std::istream& istr) {
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            istr >> field[i][j];
        }
    }
}

std::string MetalField::print() const {
    std::ostringstream ostream;
    for (auto arr : field) {
        for (auto ch : arr) {
            ostream << ch;
        }
        ostream << std::endl;
    }
    return ostream.str();
}

void Rust::rustAtPosition(MetalField& mfield, int row, int col) {
    mfield.setPosition(row, col, RUST_AMENABLE);
}

bool Rust::_isValidPos(int row, int col) const {
    if (row >= 0 && row < arrSize && col >= 0 && col < arrSize) {
        return true;
    }
    return false;
}

bool Rust::_checkIfCellCanRust(const MetalField& mfield, int row, int col) const {
    if (_isValidPos(row, col) && mfield.getPosition(row, col) != RUST_RESISTENT) {
        return true;
    }
    return false;
}

std::vector<std::pair<int, int>> Rust::_extractNewRustPositions(const MetalField& mfield) const {
    std::vector<std::pair<int, int>> rustPositions {};

    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if (mfield.getPosition(i, j) == RUST_AMENABLE) {
                if (_checkIfCellCanRust(mfield, i, j + 1)) {
                    rustPositions.push_back(std::make_pair(i, j + 1));
                }
                if (_checkIfCellCanRust(mfield, i, j - 1)) {
                    rustPositions.push_back(std::make_pair(i, j - 1));
                }
                if (_checkIfCellCanRust(mfield, i + 1, j)) {
                    rustPositions.push_back(std::make_pair(i + 1, j));
                } 
                if (_checkIfCellCanRust(mfield, i - 1, j + 1)) {
                    rustPositions.push_back(std::make_pair(i - 1, j));
                }
            }
        }
    }

    return rustPositions;
}

void Rust::spreadRust(MetalField& mfield, int rustTime) {
    for (int i = 0; i < rustTime; i++) {
        std::vector<std::pair<int, int>> posToRust = _extractNewRustPositions(mfield);
        for (auto pos : posToRust) {
            Rust::rustAtPosition(mfield, pos.first, pos.second);
        }
    }
}
