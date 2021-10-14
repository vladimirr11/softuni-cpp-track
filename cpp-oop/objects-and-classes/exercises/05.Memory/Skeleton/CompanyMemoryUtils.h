#ifndef COMPANYMEMORYUTILS_H
#define COMPANYMEMORYUTILS_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include "Company.h"

std::vector<Company> readCompaniesFromMemory(unsigned char* memory, int numCompanies) {
    std::vector<Company> companies;

    char* currMemory = reinterpret_cast<char*>(memory);

    unsigned char id = 0;
    std::string name;
    unsigned char numEmployees = 0;
    std::vector<std::pair<char, char>> employees;
    for (int i = 0; i < numCompanies; i++) {
        id = *currMemory;
        currMemory += sizeof(id);

        const size_t nameLength = strlen(currMemory);
        name = std::string(currMemory, nameLength);
        currMemory += nameLength + 1;

        numEmployees = *currMemory;
        currMemory += sizeof(numEmployees);

        employees.clear();
        for (unsigned char employee = 0; employee < numEmployees; employee++) {
            std::pair<char, char> currEmployeeInitials;

            currEmployeeInitials.first = *currMemory;
            currMemory += sizeof(currEmployeeInitials.first);

            currEmployeeInitials.second = *currMemory;
            currMemory += sizeof(currEmployeeInitials.second);

            employees.push_back(currEmployeeInitials);
        }

        companies.emplace_back(id, name, employees);
    }

    return companies;
}   

#endif // !COMPANYMEMORYUTILS_H
