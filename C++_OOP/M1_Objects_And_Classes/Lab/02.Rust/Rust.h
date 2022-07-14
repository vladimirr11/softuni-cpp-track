#ifndef RUST_H
#define RUST_H

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>

const int arrSize = 10;

using Matrix = std::array<std::array<char, arrSize>, arrSize>;

enum FieldType : char {
    HEALTHY = '.',
    RUST_RESISTENT = '#',
    RUST_AMENABLE = '!',
};

class MetalField {
public:
    MetalField() = default;
    
    void read(std::istream& istr);

    std::string print() const;

    char getPosition(int row, int col) const { return field[row][col]; }

    void setPosition(int row, int col, FieldType ftype) { field[row][col] = ftype; }

private:
    Matrix field;
};

class Rust {
public:
    Rust() = default;

    Rust(int rustTime) : _rustTime(rustTime) {}

    void readRustTime(std::istream& istr) { istr >> _rustTime; }

    void spreadRust(MetalField& mfield, int rustTime);

    static void rustAtPosition(MetalField& mfield, int row, int col);

    int getRustTime() const { return _rustTime; }

private:
    std::vector<std::pair<int, int>> _extractNewRustPositions(const MetalField& mfield) const;

    bool _isValidPos(int row, int col) const;

    bool _checkIfCellCanRust(const MetalField& mfield, int row, int col) const;

private:
    int _rustTime {};
};

#endif // !RUST_H
