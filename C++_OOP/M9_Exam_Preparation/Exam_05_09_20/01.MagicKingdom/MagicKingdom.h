#ifndef MAGICKINGDOM_H
#define MAGICKINGDOM_H

#include "Struct.h"

#include <vector>
#include <iostream>
#include <algorithm>

class MagicKingdom {
public:
    void printAll();

    friend MagicKingdom& operator<<(MagicKingdom& mKingdom, Villager& villager);

private:
    std::vector<Villager> commonerVec;
    std::vector<Villager> magiciansVec;
    std::vector<Villager> antiMagsVec;
};

#endif // !MAGICKINGDOM_H
