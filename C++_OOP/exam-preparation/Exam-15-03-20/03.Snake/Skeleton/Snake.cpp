#include "Snake.h"

Snake::Snake(const int fieldRows, const int fieldCols, const Point &startPos) : 
    _FIELD_ROWS(fieldRows), _FIELD_COLS(fieldCols), _currPos(startPos), _snakeNodes{startPos} {}

Snake::~Snake() {}

StatusCode Snake::move(const Direction dir,
                const std::vector<Point> &obstacles,
                std::vector<Point> &powerUps) {

    switch (dir) {
        case Direction::UP: {
            _currPos.row -= 1;
            if (_currPos.row < 0 || _currPos.row >= _FIELD_ROWS) {
                return StatusCode::SNAKE_DEAD;
            }

            for (const auto& obstacle : obstacles) {
                if (obstacle == _currPos) {
                    return StatusCode::SNAKE_DEAD;
                }
            }

            std::vector<Point>::iterator it;
            for (it = powerUps.begin(); it != powerUps.end(); it++) {
                if (*it == _currPos) {
                    _snakeNodes.push_front(_currPos);

                    it = powerUps.erase(it);
                    return StatusCode::SNAKE_GROWING;
                }
            }
            
            for (const auto& node : _snakeNodes) {
                if (node == _currPos) {
                    return StatusCode::SNAKE_DEAD;
                }
            }

            _snakeNodes.push_front(_currPos);
            _snakeNodes.pop_back();

            return StatusCode::SNAKE_MOVING;

        }

        case Direction::DOWN: {
            _currPos.row += 1;
            if (_currPos.row < 0 || _currPos.row >= _FIELD_ROWS) {
                return StatusCode::SNAKE_DEAD;
            }

            for (const auto& obstacle : obstacles) {
                if (obstacle == _currPos) {
                    return StatusCode::SNAKE_DEAD;
                }
            }

            std::vector<Point>::iterator it;
            for (it = powerUps.begin(); it != powerUps.end(); it++) {
                if (*it == _currPos) {
                    _snakeNodes.push_front(_currPos);

                    it = powerUps.erase(it);
                    return StatusCode::SNAKE_GROWING;
                }
            }

            for (const auto& node : _snakeNodes) {
                if (node == _currPos) {
                    return StatusCode::SNAKE_DEAD;
                }
            }

            _snakeNodes.push_front(_currPos);
            _snakeNodes.pop_back();

            return StatusCode::SNAKE_MOVING;

        }

        case Direction::LEFT: {
            _currPos.col -= 1;
            if (_currPos.col < 0 || _currPos.col >= _FIELD_COLS) {
                return StatusCode::SNAKE_DEAD;
            }

            for (const auto& obstacle : obstacles) {
                if (obstacle == _currPos) {
                    return StatusCode::SNAKE_DEAD;
                }
            }

            std::vector<Point>::iterator it;
            for (it = powerUps.begin(); it != powerUps.end(); it++) {
                if (*it == _currPos) {
                    _snakeNodes.push_front(_currPos);

                    it = powerUps.erase(it);
                    return StatusCode::SNAKE_GROWING;
                }
            }

            for (const auto& node : _snakeNodes) {
                if (node == _currPos) {
                    return StatusCode::SNAKE_DEAD;
                }
            }

            _snakeNodes.push_front(_currPos);
            _snakeNodes.pop_back();

            return StatusCode::SNAKE_MOVING;

        }

        case Direction::RIGHT: {
            _currPos.col += 1;
            if (_currPos.col < 0 || _currPos.col >= _FIELD_COLS) {
                return StatusCode::SNAKE_DEAD;
            }

            for (const auto& obstacle : obstacles) {
                if (obstacle == _currPos) {
                    return StatusCode::SNAKE_DEAD;
                }
            }

            std::vector<Point>::iterator it;
            for (it = powerUps.begin(); it != powerUps.end(); it++) {
                if (*it == _currPos) {
                    _snakeNodes.push_front(_currPos);

                    it = powerUps.erase(it);
                    return StatusCode::SNAKE_GROWING;
                }
            }

            for (const auto& node : _snakeNodes) {
                if (node == _currPos) {
                    return StatusCode::SNAKE_DEAD;
                }
            }

            _snakeNodes.push_front(_currPos);
            _snakeNodes.pop_back();

            return StatusCode::SNAKE_MOVING;
        }

    }

    return StatusCode::STATUS_UNKNOWN;
}

std::deque<Point>& Snake::getSnakeNodes() {
    return _snakeNodes;
}
