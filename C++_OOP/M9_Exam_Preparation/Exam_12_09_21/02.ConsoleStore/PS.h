#ifndef PS_H
#define PS_H

#include "Console.h"

class PS : public Console {
public:
    PS(int price, int quality, int generatio);

    int getGeneration() const;
    
private:
    int _price;
    int _quality;
    int _generation;
};

#endif // !PS_H
