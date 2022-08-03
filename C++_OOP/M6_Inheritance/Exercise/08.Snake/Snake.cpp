#include "Snake.h"

#include <iostream>
#include <algorithm>

static Point getFuturePos(const Point& currPos, const Direction dir) {
    Point futurePos = currPos;

    switch (dir){
    case Direction::UP:
        --futurePos.row;
        break;
    case Direction::LEFT:
        --futurePos.col;
        break;
    case Direction::DOWN:
        ++futurePos.row;
        break;
    case Direction::RIGHT:
        ++futurePos.col;
        break;
    default:
        std::cerr << "Recieved invalid direction: " << static_cast<int>(dir) << std::endl;
        break;
    }

    return futurePos;
}

static bool isValidMove(const std::vector<Point>& obstacles, const std::deque<Point>& snakeNodes,
                        const int fieldRows, const int fieldCols, const Point& pos) {
    
    if (0 > pos.row || 0 > pos.col) {
        return false;
    }

    if (pos.row >= fieldRows || pos.col >= fieldCols) {
        return false;
    }

    // collide with obstacle
    const auto obstIt = std::find_if(obstacles.begin(), obstacles.end(), [&pos](const Point& obstacle) {
                            return obstacle == pos;});
    
    if (obstIt != obstacles.end()) {
        return false;
    }

    // collide with self
    const auto selfIt = std::find_if(snakeNodes.begin(), snakeNodes.end(), [&pos](const Point& node) {
                            return node == pos;});

    if (selfIt != snakeNodes.end()) {
        return false;
    }

    return true;
}

static bool shouldPowerUp(const std::vector<Point>& powerUps, const Point& pos, size_t collisionIndx) {
    const auto it = std::find_if(powerUps.begin(), powerUps.end(), [&pos](const Point& node) {
                        return node == pos;});
    
    if (it != powerUps.end()) {
        collisionIndx = it - powerUps.begin();
        return true;
    }

    return false;
}

Snake::Snake(const int fieldRows, const int fieldCols, const Point& startPos) :
    _FIELD_ROWS(fieldRows), _FIELD_COLS(fieldCols), _currPos(startPos), _snakeNodes{startPos} {}

Snake::~Snake() {}

StatusCode Snake::move(const Direction dir, const std::vector<Point>& obstacles, std::vector<Point>& powerUps) {
    _currPos = getFuturePos(_currPos, dir);
    const bool isSnakeMoveValid = isValidMove(obstacles, _snakeNodes, _FIELD_ROWS, _FIELD_COLS, _currPos);

    if (!isSnakeMoveValid) {
        return StatusCode::SNAKE_DEAD;
    }

    // snake move
    _snakeNodes.push_front(_currPos);
    const auto tail = _snakeNodes.back();
    _snakeNodes.pop_back();

    size_t collideIdx = 0;
    const bool shouldSnakePowerUp = shouldPowerUp(powerUps, _currPos, collideIdx);

    if (shouldSnakePowerUp) {
        _snakeNodes.push_back(tail);
        powerUps.erase(powerUps.begin() + collideIdx);

        return StatusCode::SNAKE_GROWING;
    }

    return StatusCode::SNAKE_MOVING;
}

std::deque<Point>& Snake::getSnakeNodes() {
    return _snakeNodes;
}
