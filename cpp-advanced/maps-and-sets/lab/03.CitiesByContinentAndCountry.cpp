#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

std::map<std::string, std::map<std::string, std::vector<std::string>>> getInputCountries() {
    int numberInputCountries = 0;
    std::cin >> numberInputCountries;
    std::cin.ignore();

    std::map<std::string, std::map<std::string, std::vector<std::string>>> continentCountryMap = {};

    for (int i = 0; i < numberInputCountries; i++) {
        std::string iLine;
        getline(std::cin, iLine);
        std::istringstream iStream(iLine);
        
        std::string continent;
        std::string country;
        std::string capital;

        iStream >> continent >> country >> capital;

        continentCountryMap[continent][country].push_back(capital);
    }

    return continentCountryMap;
}

int main() {
    std::map<std::string, std::map<std::string, std::vector<std::string>>> continentCountryMap = getInputCountries();

    for (const auto& continentIt : continentCountryMap) {
        std::cout << continentIt.first << ":" << std::endl;
        for (const auto& countryIt : continentIt.second) {
            std::cout << "  " << countryIt.first << " -> "; 
            std::string answer;
            for (const auto& capitaIt: countryIt.second) {
                answer.append(capitaIt).append(", ");
            } 
            answer.pop_back();
            answer.pop_back();
            std::cout << answer << std::endl;
        }
    }

    return 0;
}
