#ifndef ANIMALTYPES_H
#define ANIMALTYPES_H

#include "AnimalCharacteristics.h"

#include <string>
#include <vector>
#include <iostream>

class AnimalTypes {
public:
    AnimalTypes();

    void print();

    friend AnimalTypes& operator<<(AnimalTypes& aType, AnimalCharacteristics& aChars);

private:
    std::vector<AnimalCharacteristics> catsVec;
    std::vector<AnimalCharacteristics> dogsVec;
    std::vector<AnimalCharacteristics> bunniesVec;
};

#endif // !ANIMALTYPES_
