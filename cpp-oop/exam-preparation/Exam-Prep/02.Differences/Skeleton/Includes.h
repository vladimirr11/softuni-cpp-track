#ifndef INCLUDES_H
#define INCLUDES_H

#include <vector>
#include <iostream>
#include <math.h>

#include "City.h"
#include "CityDiff.h"

std::istream& operator>>(std::istream& in, City& city) {
    unsigned int censusYear = 0;
    std::string cityName;
    size_t population = 0;

    in >> cityName >> population >> censusYear;
    city = City(censusYear, cityName, population);

    return in;
}

CityDiff operator-(City& firstCity, City& secondCity) {
    unsigned int fcCensusYear = firstCity.getCensusYear();
    unsigned int scCensusYear = secondCity.getCensusYear();

    std::string fcCityName = firstCity.getName();
    std::string scCityName = secondCity.getName();

    long long fcPopulation = firstCity.getPopulation();
    long long scPopulation = secondCity.getPopulation();

    std::string citiesDiffInfo;
    long long citiesDiffPopulation = 0;
    if (fcCityName == scCityName) {
        citiesDiffInfo = fcCityName.append(" (").append(std::to_string(fcCensusYear)).
                                    append(" vs. ").append(std::to_string(scCensusYear)).append(")");
    } else {
        citiesDiffInfo = fcCityName.append(" (").append(std::to_string(fcCensusYear)).append(") vs. ").
                                    append(scCityName).append(" (").append(std::to_string(scCensusYear)).append(")");
    }

    bool isPositiveNumber = true;
    if (fcPopulation >= scPopulation) {
        isPositiveNumber = true;
    } else {
        isPositiveNumber = false;
    }

    citiesDiffPopulation = std::abs(fcPopulation - scPopulation);

    CityDiff diff(citiesDiffInfo, citiesDiffPopulation, isPositiveNumber);

    return diff;
}

#endif // !INCLUDES_H
