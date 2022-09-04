#ifndef BOMBERMAN_H
#define BOMBERMAN_H

// #include "InputParser.h"
#include "Defines.h"

class BomberMan {
public:
    void bombPowerUp();

    void bombPowerDown();

    int placeBomb(FieldData& fdata, int bombRow, int bombCol);

    int getBombPower();

private:
    int _bombPower = 0;
};

#endif // !BOMBERMAN_H
