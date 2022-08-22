#ifndef NUMBERFILTER_H
#define NUMBERFILTER_H

#include "CharFilter.h"

class NumberFilter : public CharFilter {
public:
    NumberFilter(char lowerBound, char upperBound) 
        : CharFilter(lowerBound, upperBound) {}
};

#endif // !NUMBERFILTER_H
