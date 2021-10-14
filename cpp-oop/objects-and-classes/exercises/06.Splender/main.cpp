#include <iostream>
#include <vector>
#include <string>

#include "Defines.h"

std::string toString(Direction dir) {
    switch (dir) {
    case Direction::SOUTH:
        return "SOUTH";
    case Direction::EAST:
        return "EAST";
    case Direction::NORTH:
        return "NORTH";
    case Direction::WEST:
        return "WEST";
    default:
        std::cerr << "Recieved invalid dir: " << static_cast<int>(dir) << std::endl;
        return "UNSUPPORTED";
    }
}

struct Pos {
    Pos() {}

    Pos(size_t inputRow, size_t inputCol) : row(inputRow), col(inputCol) {}

    size_t row = 0;
    size_t col = 0;
};

Pos getFuturePos(const Pos& currPos, Direction dir) {
    switch (dir) {
    case Direction::SOUTH:
        return Pos(currPos.row + 1, currPos.col);
    case Direction::EAST:
        return Pos(currPos.row, currPos.col + 1);
    case Direction::NORTH:
        return Pos(currPos.row - 1, currPos.col);
    case Direction::WEST:
        return Pos(currPos.row, currPos.col - 1);
    default:
        std::cerr << "Recieved invalid dir: " << static_cast<int>(dir) << std::endl;
        return Pos();
    }
}

Direction toDirection(char tile) {
    switch (tile) {
    case SOUTH_TYPE:
        return Direction::SOUTH;
    case EAST_TYPE:
        return Direction::EAST;
    case NORTH_TYPE:
        return Direction::NORTH;
    case WEST_TYPE:
        return Direction::WEST;
    default:
        std::cerr << "Recieved invalid tile" << std::endl;
        return Direction::SOUTH;
    }
}

class Map {
public:
    void readInput() {
        int rows = 0, cols = 0;
        std::cin >> rows >> cols;
        std::cin.ignore();

        _data.resize(rows);
        for (auto& row : _data) {
            getline(std::cin, row);
        }
    }

    Pos getInitialPos() {                
        const size_t rows = _data.size();
        for (size_t row = 0; row < rows; row++) {
            const size_t cols = _data[row].size();
            for (size_t col = 0; col < cols; col++) {
                if (_data[row][col] == START_MARKER) {
                    return Pos(row, col);
                }
            }
        }

        std::cerr << "No start position found!" << std::endl;
        return Pos();
    }

    char getTile(const Pos& pos) {
        return _data[pos.row][pos.col];
    }

private:
    std::vector<std::string> _data;
};

class Splender {
public:
    void setInitialPos(const Pos& pos) {
        _currPos = pos;
    }

    void act(Map& map) {
        const Pos futurePos = getFuturePos(_currPos, _currDir);
        const char futureTile = map.getTile(futurePos);

        _dirToPrint = _currDir;

        if (futureTile == END_MARKER) {
            _isRunning = false;
            return;
        }

        if (shouldChangePos(futureTile)) {
            _currDir = toDirection(futureTile);
        }

        _currPos = futurePos;
    }

    bool isRunning() {
        return _isRunning;
    }

    void printMove() {
        std::cout << toString(_dirToPrint) << std::endl;
    }

    bool shouldChangePos(char tile) {
        if (tile == SOUTH_TYPE ||
            tile == EAST_TYPE ||
            tile == NORTH_TYPE ||
            tile == WEST_TYPE) {

            return true;
        }
        
        return false;
    }

private:
    Pos _currPos;
    Direction _currDir = Direction::SOUTH;
    Direction _dirToPrint = Direction::SOUTH;
    bool _isRunning = true;
};

class Game {
public:
    void readInput() {
        _map.readInput();
        _splender.setInitialPos(_map.getInitialPos());
    }

    void act() {
        _splender.act(_map);
    }

    void printMove() {
        _splender.printMove();
    }

    bool isRunning() {
        return _splender.isRunning();
    }

private:
    Map _map;
    Splender _splender;
};

int main() {
    Game game;
    
    game.readInput();
    while (game.isRunning()) {
        game.act();
        game.printMove();
    }

    return 0;
}
