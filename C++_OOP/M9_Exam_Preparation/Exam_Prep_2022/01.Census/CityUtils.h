#ifndef CITYUTILS_H
#define CITYUTILS_H

#include <string>
#include <vector>
#include <map>

#include "City.h"

City* initCity(std::string name, size_t population) {
    City* c = new City(name, population);
    return c;
}

std::map<size_t, const City*> groupByPopulation(std::vector<const City*> cities, size_t& totalPopulation) {
    std::map<size_t, const City*> populationMap;

    totalPopulation = 0;
    for (auto it = cities.begin(); it != cities.end(); ++it) {
        populationMap[(*it)->getPopulation()] = *it;
        totalPopulation += (*it)->getPopulation();
    }
    return populationMap;
}

#endif // !CITYUTILS_H
