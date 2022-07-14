#ifndef STORE_H
#define STORE_H

#include "Defines.h"
#include "Console.h"
#include "PS.h"
#include "Xbox.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Store {
public:
    void addPs(int price, int quantity, int generation);

    void addXbox(int price, int quantity);

    void remove(ConsoleType ctype);

    void sortByPrice(ConsoleType ctype);

    void sortByQuality(ConsoleType ctype);

    void print(ConsoleType ctype);

private:
    std::vector<PS> _pSConsolesVec;
    std::vector<Xbox> _xBoxConsolesVec;

};

#endif // !STORE_H
