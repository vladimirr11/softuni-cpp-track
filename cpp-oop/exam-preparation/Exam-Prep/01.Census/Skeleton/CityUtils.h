#ifndef CITYUTILS_H
#define CITYUTILS_H

#include "City.h"

#include <map>

const City* initCity(const std::string& name, size_t population) {
    const City* c = new City(name, population);
    return c;
}

std::map<size_t, const City*> groupByPopulation(std::vector<const City*> cities, size_t& totalPopulation) {
    std::map<size_t, const City*> cityPopulationMap;
    
    totalPopulation = 0;
    for (size_t i = 0; i < cities.size(); i++) {
        cityPopulationMap[cities[i]->getPopulation()] = cities[i];

        totalPopulation += cities[i]->getPopulation();
    }

    return cityPopulationMap;
}   

#endif // !CITYUTILS_H
