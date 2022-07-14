#ifndef COMPANYMEMORYUTILS_H
#define COMPANYMEMORYUTILS_H

#include <cstring>
#include "Company.h"

typedef unsigned char byte;

std::vector<Company> readCompaniesFromMemory(byte* memory, int numCompanies) {
    std::vector<Company> companiesData;
    for (int i = 0; i < numCompanies; i++) {
        int id = *memory++;

        const size_t nameLength = strlen(reinterpret_cast<const char*>(memory));
        std::string name(reinterpret_cast<char*>(memory), nameLength);
        
        memory += nameLength;

        int numEmpl = *(++memory);
        std::vector<std::pair<char, char>> employees;
        employees.reserve(numEmpl);
        for (int i = 0; i < numEmpl; i++) {
            std::pair<char, char> empl;
            empl.first = *(++memory);
            empl.second = *(++memory);
            employees.push_back(empl);
        }

        companiesData.emplace_back(id, name, employees);
        memory++;
    }

    return companiesData;
}

#endif // !COMPANYMEMORYUTILS_H
