#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <map>

// #include "Defines.h"

const size_t NUM_TELEPORTS = 2;

enum class Direction {
    SOUTH, EAST, NORTH, WEST
};

enum TileType {
    END_MARKER = '$',
    START_MARKER = '@',
    TELEPORT = 'T',
    INVERTER = 'I',
    OBSTACLE = 'X',
    END_OF_MAP = '#',
    BEER = 'B',
    SOUTH_TYPE = 'S',
    EAST_TYPE = 'E',
    NORTH_TYPE = 'N',
    WEST_TYPE = 'W'
};

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

    Pos(const Pos& other) : row(other.row), col(other.col) {}

    Pos& operator=(const Pos& other) {
        row = other.row;
        col = other.col;
        return *this;
    }

    size_t row = 0;
    size_t col = 0;

    bool operator==(const Pos& other) const {
        if (row == other.row && col == other.col) {
            return true;
        }
        return false;
    }
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
    void read(std::istream& istr) {
        int rows = 0, cols = 0;
        istr >> rows >> cols;
        istr.ignore();

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

    std::array<Pos, NUM_TELEPORTS> findTeleports() {
        int telNumber {};
        for (int i = 0; i < _data.size(); i++) {
            for (int j = 0; j < _data[i].size(); j++) {
                if (_data[i][j] == TELEPORT) {
                    _teleportsPos[telNumber] = Pos(i, j);
                    telNumber++;
                }
            }
        }

        return _teleportsPos;
    }

    Pos getFirstTeleport() const {
        return _teleportsPos[0];
    }

    Pos getSecondTeleport() const {
        return _teleportsPos[1];
    }

    char& getTile(const Pos& pos) {
        return _data[pos.row][pos.col];
    }

    void jumpFirstTeleport(Pos& pos) const {
        pos = getFirstTeleport();
    }

    void jumpSecondTeleport(Pos& pos) const {
        pos = getSecondTeleport();
    }
 
private:
    std::vector<std::string> _data;
    std::array<Pos, NUM_TELEPORTS> _teleportsPos;
};

class Splender {
public:
    void setInitialPos(const Pos& pos) {
        _currPos = pos;
    }

    void act(Map& map) {
        Pos futurePos = getFuturePos(_currPos, _currDir);
        const char futureTile = map.getTile(futurePos);

        _dirToPrint = _currDir;

        if (futureTile == END_MARKER) {
            _isRunning = false;
            return;
        } else if (futureTile == INVERTER) {
            _setInverter();
            _currPos = futurePos;
            return;
        } else if (futureTile == BEER) {
            _setBrakerMode();
            _currPos = futurePos;
            return;
        } else if (futureTile == TELEPORT) {
            _teleport(map, futurePos);
            _currPos = futurePos;
            return;
        }

        if (shouldChangePos(futureTile)) {
            _currDir = toDirection(futureTile);
        } else if (isObstacle(futureTile)) {
            if (_inBrakerMode && futureTile == OBSTACLE) {
                _destroyObstacle(map, futurePos);
            } else {
                _prioritiseSplender(map, _hasInverter);
                return;
            }
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
        if (tile == SOUTH_TYPE || tile == EAST_TYPE || tile == NORTH_TYPE || tile == WEST_TYPE) {
            return true;
        }
        return false;
    }

    bool isObstacle(char tile) {
        if (tile == OBSTACLE || tile == END_OF_MAP) {
            return true;
        }
        return false;
    }

private:
    bool _canAdjustSouth(Map& map, Pos pos) const {
        // move SOUTH
        pos.row++;
        if (map.getTile(pos) != END_OF_MAP && map.getTile(pos) != OBSTACLE) {
            return true;
        }
        return false;
    }

    bool _canAdjustEast(Map& map, Pos pos) const {
        // move EAST
        pos.col++;
        if (map.getTile(pos) != END_OF_MAP && map.getTile(pos) != OBSTACLE) {
            return true;
        }
        return false;
    }

    bool _canAdjustNorth(Map& map, Pos pos) const {
        // move NORTH
        pos.row--;
        if (map.getTile(pos) != END_OF_MAP && map.getTile(pos) != OBSTACLE) {
            return true;
        }
        return false;
    }

    bool _canAdjustWest(Map& map, Pos pos) const {
        // move WEST
        pos.col--;
        if (map.getTile(pos) != END_OF_MAP && map.getTile(pos) != OBSTACLE) {
            return true;
        }
        return false;
    }

    void _setInverter() {
        if (_hasInverter) {
            _hasInverter = false;
        } else {
            _hasInverter = true;
        }
    }

    void _setBrakerMode() {
        if (_inBrakerMode) {
            _inBrakerMode = false;
        } else {
            _inBrakerMode = true;
        }
    }

    void _teleport(const Map& map, Pos& pos) {
        if (map.getFirstTeleport() == pos) {
            map.jumpSecondTeleport(pos);
        } else {
            map.jumpFirstTeleport(pos);
        }
    }

    void _prioritiseSplender(Map& map, bool hasInverter) {
        if (!_hasInverter) {
            if (_canAdjustSouth(map, _currPos)) {
                _currDir = Direction::SOUTH;
                _currPos.row++;
                _dirToPrint = _currDir;
                return;
            } else if (_canAdjustEast(map, _currPos)) {
                _currDir = Direction::EAST;
                _currPos.col++;
                _dirToPrint = _currDir;
                return;
            } else if (_canAdjustNorth(map, _currPos)) {
                _currDir = Direction::NORTH;
                _currPos.row--;
                _dirToPrint = _currDir;
                return;
            } else {
                _currDir = Direction::WEST;
                _currPos.col--;
                _dirToPrint = _currDir;
                return;
            }

        } else {
            if (_canAdjustWest(map, _currPos)) {
                _currDir = Direction::WEST;
                _currPos.col--;
                _dirToPrint = _currDir;
                return;
            } else if (_canAdjustNorth(map, _currPos)) {
                _currDir = Direction::NORTH;
                _currPos.row--;
                _dirToPrint = _currDir;
                return;
            } else if (_canAdjustEast(map, _currPos)) {
                _currDir = Direction::EAST;
                _currPos.col++;
                _dirToPrint = _currDir;
                return;
            } else {
                _currDir = Direction::SOUTH;
                _currPos.row++;
                _dirToPrint = _currDir;
                return;
            }
        }
    }

    void _destroyObstacle(Map& map, const Pos& pos) {
        map.getTile(pos) = ' ';
    }

private:
    Pos _currPos;
    Direction _currDir = Direction::SOUTH;
    Direction _dirToPrint = Direction::SOUTH;
    bool _isRunning = true;
    bool _hasInverter = false;
    bool _inBrakerMode = false;
};

class Game {
public:
    void readInput() {
        _map.read(std::cin);
        _splender.setInitialPos(_map.getInitialPos());
        _map.findTeleports();
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
