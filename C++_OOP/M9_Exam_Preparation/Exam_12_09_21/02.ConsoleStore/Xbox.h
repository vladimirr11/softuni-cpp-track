#ifndef XBOX_H
#define XBOX_H

#include "Console.h"

class Xbox : public Console {
public:
    Xbox(int price, int quality);

private:
    int _price;
    int _quality;
};

#endif // !XBOX_H
