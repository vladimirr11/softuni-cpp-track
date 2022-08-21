#include <iostream>
#include <algorithm>

#include "Company.h"

std::vector<Company> readInputCompanies() {
    std::vector<Company> companiesVec;

    std::string line;
    while (getline(std::cin, line) && line != "end") {
        std::istringstream istr(line);
        
        std::string companyName;
        int companyId;

        istr >> companyName >> companyId;

        companiesVec.emplace_back(companyId, companyName);
    }

    return companiesVec;
}

int main() {
    std::vector<Company> companiesVec = readInputCompanies();

    std::string sortParameter;
    std::cin >> sortParameter;
    std::cin.ignore();

    std::sort(companiesVec.begin(), companiesVec.end(), [&sortParameter](const Company& c1, const Company& c2) {
        return sortParameter == "id" ? c1.getId() < c2.getId() : c1.getName() < c2.getName();
    });

    for (const Company& c : companiesVec) {
        std::cout << c.getName() << " " << c.getId() << std::endl;
    }

    return 0;
}
