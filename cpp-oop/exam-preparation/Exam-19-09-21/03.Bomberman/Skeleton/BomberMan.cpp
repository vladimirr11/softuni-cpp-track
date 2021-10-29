#include "BomberMan.h"
#include "Defines.h"

void BomberMan::bombPowerUp() {
    _bombPower++;
}

void BomberMan::bombPowerDown() {
    _bombPower--;
    if (_bombPower < 0) {
        _bombPower = 0;
    }
}

int upDir(FieldData& fd, int currRow, int currCol, int bombPower) {
    int score = 0;
    for (int i = 0; i <= bombPower; i++) {
        if (currRow - i >= 0) {
            score += fd[currRow - i][currCol] - '0';
            fd[currRow - i][currCol] = '0';
        } else {
            break;
        }
    }

    return score;
}

int downDir(FieldData& fd, int currRow, int currCol, int bombPower) {
    int score = 0;
    for (int i = 0; i <= bombPower; i++) {
        if (currRow + i < fd.size()) {
            score += fd[currRow + i][currCol] - '0';
            fd[currRow + i][currCol] = '0';
        } else {
            break;
        }
    }

    return score;
}

int leftDir(FieldData& fd, int currRow, int currCol, int bombPower) {
    int score = 0;
    for (int i = 0; i <= bombPower; i++) {
        if (currCol - i >= 0) {
            score += fd[currRow][currCol - i] - '0';
            fd[currRow][currCol - i] = '0';
        } else {
            break;
        }
    }

    return score;
}

int rightDir(FieldData& fd, int currRow, int currCol, int bombPower) {
    int score = 0;
    for (int i = 0; i <= bombPower; i++) {
        if (currCol + i < fd[currRow].size()) {
            score += fd[currRow][currCol + i] - '0';
            fd[currRow][currCol + i] = '0';
        } else {
            break;
        }
    }

    return score;
}

int BomberMan::placeBomb(FieldData& fdata, int bombRow, int bombCol) {
    int score = 0;

    if (_bombPower == 0) {
        score += fdata[bombRow][bombCol] - '0';
        fdata[bombRow][bombCol] = '0';
    } else {
        score += upDir(fdata, bombRow, bombCol, _bombPower);
        score += downDir(fdata, bombRow, bombCol, _bombPower);
        score += leftDir(fdata, bombRow, bombCol, _bombPower);
        score += rightDir(fdata, bombRow, bombCol, _bombPower);
    }

    return score;
}

int BomberMan::getBombPower() {
    return _bombPower;
}
