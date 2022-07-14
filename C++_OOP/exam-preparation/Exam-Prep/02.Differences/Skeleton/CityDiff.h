#ifndef CITYDIFF_H
#define CITYDIFF_H

#include <string>
#include <iostream>

class CityDiff {
public:
    CityDiff(const std::string& name, long long population, bool isPositive) : 
        _name(name), _cityPopulation(population), _isPositive(isPositive) {} 

    friend std::ostream& operator<<(std::ostream& outpuStream, const CityDiff& citiesDiff);

private:
    std::string _name;
    long long _cityPopulation;
    bool _isPositive;
};

std::ostream& operator<<(std::ostream& outpuStream, const CityDiff& citiesDiff) {
    outpuStream << citiesDiff._name << std::endl;

    if (citiesDiff._isPositive) {
        outpuStream << "population: +" << citiesDiff._cityPopulation << std::endl;
    } else {
        outpuStream << "population: -" << citiesDiff._cityPopulation << std::endl;
    }

    return outpuStream;
}

#endif // !CITYDIFF_H
