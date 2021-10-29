#ifndef STATISTICS_H
#define STATISTICS_H

#include "Structs.h"

#include <vector>
#include <iostream>
#include <algorithm>

class Statistics {
public:
    void printStatistics();

    friend Statistics& operator<<(Statistics& stat, PersonInfo& info);

private:
    std::vector<PersonInfo> minorsVec;
    std::vector<PersonInfo> adultsVec;
    std::vector<PersonInfo> eldersVec;
};

#endif // !STATISTICS_H
