#ifndef CHARFILTER_H
#define CHARFILTER_H

#include "Filter.h"

class CharFilter : public Filter {
public:
    CharFilter(char lowerBound, char upperBound) : 
        _lowerBound(lowerBound), _upperBound(upperBound) {}

    bool shouldFilterOut(char symbol) const final {
        return (_lowerBound <= symbol) && (symbol <= _upperBound);
    }

private:
    char _lowerBound;
    char _upperBound;
};

#endif // !CHARFILTER_H
