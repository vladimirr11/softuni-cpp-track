#ifndef SCIENTIFICFIELD_H
#define SCIENTIFICFIELD_H

#include "Discovery.h"

#include <vector>
#include <iostream>
#include <algorithm>

class ScientificField {
public:
    void print();

    friend ScientificField& operator<<(ScientificField& sField, Discovery& discovery);

private:
    std::vector<Discovery> philosophyVec;
    std::vector<Discovery> linguisticsVec;
    std::vector<Discovery> physicsVec;
    std::vector<Discovery> chemistryVec;
};

#endif // !SCIENTIFICFIELD_H
