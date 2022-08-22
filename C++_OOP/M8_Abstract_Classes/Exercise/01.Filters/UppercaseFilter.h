#ifndef UPPERCASEFILTER_H
#define UPPERCASEFILTER_H

#include "CharFilter.h"

class UppercaseFilter : public CharFilter {
public:
    UppercaseFilter(char lowerBound, char upperBound) 
        : CharFilter(lowerBound, upperBound) {}
};

#endif // !UPPERCASEFILTER_H
