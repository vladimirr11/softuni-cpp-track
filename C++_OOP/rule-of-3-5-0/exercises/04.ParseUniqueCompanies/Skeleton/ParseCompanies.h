#ifndef PARSECOMPANIES_H
#define PARSECOMPANIES_H

#include <string>
#include <sstream>
#include <unordered_set>
#include <vector>

#include "Company.h"

Company* parseUniqueCompanies(const std::string& input, int& numCompanies, 
                                std::string (*getter) (const Company&)) {

    std::istringstream istr(input);

    std::unordered_set<std::string> uniqueCompaniesSet;
    
    std::string name;
    int id = 0;
    std::vector<Company> companiesVec;

    while (istr >> id >> name) {
        Company c(id, name);
        const std::string currUniqueComp = getter(c);

        const auto it = uniqueCompaniesSet.find(currUniqueComp);
        if (it == uniqueCompaniesSet.end()) {
            uniqueCompaniesSet.insert(currUniqueComp);
            companiesVec.emplace_back(id, name);
        }
    }  

    const size_t companiesVecSize = companiesVec.size();
    Company* companiesRawArray = new Company[companiesVecSize];
    for (size_t i = 0; i < companiesVecSize; i++) {
        companiesRawArray[i] = companiesVec[i];
    }                              

    numCompanies = static_cast<int>(companiesVecSize);

    return companiesRawArray;
}

#endif // !PARSECOMPANIES_H
