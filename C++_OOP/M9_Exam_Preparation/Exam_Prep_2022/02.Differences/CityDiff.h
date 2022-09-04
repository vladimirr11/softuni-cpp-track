#ifndef CITYDIFF_H
#define CITYDIFF_H

#include "City.h"

class CityDiff {
public:
    CityDiff() = default;

    CityDiff(const std::string& cn1, const std::string& cn2, unsigned year1, unsigned year2, const int diff) 
        : _cityName1(cn1), _cityName2(cn2), _year1(year1), _year2(year2), _populationDiff(diff) {}
    
    std::string getCityName1() const {
        return _cityName1;
    }

    std::string getCityName2() const {
        return _cityName2;
    }

    unsigned getYear1() const {
        return _year1;
    }

    unsigned getYear2() const {
        return _year2;
    }

    int getPopulationDiff() const {
        return _populationDiff;
    }

private:
    std::string _cityName1;
    std::string _cityName2;
    unsigned _year1;
    unsigned _year2;
    int _populationDiff;
};

#endif // !CITYDIFF_H
