#ifndef ORDEREDINSERTER_H
#define ORDEREDINSERTER_H

#include <string>
#include <vector>
#include <algorithm>

#include "Company.h"

class OrderedInserter {
public:
    OrderedInserter(std::vector<const Company*>& companies)
    : _companies(companies) {} 

    void insert(const Company* company) {
        _companies.push_back(company);

        size_t vecSize = _companies.size();

        // bubble sort
        for (size_t i = 0; i < vecSize - 1; i++) {
            for (size_t j = 0; j < vecSize - 1; j++) {
                if (_companies[j]->getId() > _companies[j + 1]->getId()) {
                    const Company* tempCompany = _companies[j];
                    _companies[j] = _companies[j + 1];
                    _companies[j + 1] = tempCompany;
                }
            }
        }

    }

private:
    std::vector<const Company*>& _companies;
};

#endif // !ORDEREDINSERTER_H
