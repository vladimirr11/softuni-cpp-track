#include <iostream>
#include <array>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <tuple>

using CityProductMap = std::map<std::string, double>;

CityProductMap readInput() {
    int numCities {};
    std::cin >> numCities;
    std::cin.ignore();

    CityProductMap cityProdMap;
    while (true) {
        std::string city;
        std::getline(std::cin >> std::ws, city);
        std::string price;
        std::getline(std::cin >> std::ws, price);
        std::string count;
        std::getline(std::cin >> std::ws, count);

        cityProdMap[city] += std::stod(price) * std::stod(count);

        if (cityProdMap.size() == numCities) {
            break;
        }
    }

    return cityProdMap;
}

void printRes(CityProductMap& cityProdMap) {
    for (const auto c : cityProdMap) {
        std::cout << c.first << " " << c.second << std::endl;
    }
} 

int main() {
    auto cityProdMap = readInput();

    printRes(cityProdMap);

    return 0;
}
