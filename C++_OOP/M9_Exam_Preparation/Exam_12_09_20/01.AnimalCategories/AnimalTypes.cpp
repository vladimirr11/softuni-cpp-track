#include "AnimalTypes.h"

AnimalTypes::AnimalTypes() {}

void AnimalTypes::print() {
    std::cout << "Cat Breeds:" << std::endl;
    for (const auto& cat : catsVec) {
        std::cout << cat.name << " - " << cat.breed << " - " << cat.age << std::endl;
    }

    std::cout << "Dog Breeds:" << std::endl;
    for (const auto& dog : dogsVec) {
        std::cout << dog.name << " - " << dog.breed << " - " << dog.age << std::endl;
    }

    std::cout << "Bunny Breeds:" << std::endl;
    for (const auto& bunny : bunniesVec) {
        std::cout << bunny.name << " - " << bunny.breed << " - " << bunny.age << std::endl;
    }

}

AnimalTypes& operator<<(AnimalTypes& aType, AnimalCharacteristics& aChars) {
    if (aChars.category == 1) {
        aType.catsVec.push_back(aChars);
    } else if (aChars.category == 2) {
        aType.dogsVec.push_back(aChars);
    } else if (aChars.category == 3) {
        aType.bunniesVec.push_back(aChars);
    }

    return aType;
}
