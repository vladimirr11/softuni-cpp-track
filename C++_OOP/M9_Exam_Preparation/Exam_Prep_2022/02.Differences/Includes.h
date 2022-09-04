#ifndef INCLUDES_H
#define INCLUDES_H

#include <iostream>
#include <vector>
#include <string>

#include "City.h"
#include "CityDiff.h"

std::istream& operator>>(std::istream& istr, City& city) {
    std::string name;
    size_t population;
    int year;
    istr >> name >> population >> year;
    city = City(year, name, population);
    return istr;
}

CityDiff operator-(const City& c1, const City& c2) {
    int populationDiff = c1.getPopulation() - c2.getPopulation();
    CityDiff cdiff(c1.getName(), c2.getName(), c1.getCensusYear(), c2.getCensusYear(), populationDiff);
    return cdiff;
}

std::ostream& operator<<(std::ostream& ostr, const CityDiff& cdiff) {
    if (cdiff.getCityName1() == cdiff.getCityName2()) { 
        ostr << cdiff.getCityName1() << " (" << cdiff.getYear1() << " vs. " << cdiff.getYear2() << ")\npopulation: ";
    } else {
        ostr << cdiff.getCityName1() << " (" << cdiff.getYear1() << ") vs. " << cdiff.getCityName2() << " (" 
        << cdiff.getYear2() << ")\npopulation: ";
    }

    ostr << std::showpos << cdiff.getPopulationDiff() << std::endl;

    return ostr;
}

#endif // !INCLUDES_H
