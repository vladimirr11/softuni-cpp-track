#ifndef LOWERCASEFILTER_H
#define LOWERCASEFILTER_H

#include "CharFilter.h"

class LowercaseFilter : public CharFilter {
public:
    LowercaseFilter(char lowerBound, char upperBound) : 
        CharFilter(lowerBound, upperBound) {}
};

#endif // !LOWERCASEFILTER_H
