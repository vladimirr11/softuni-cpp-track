#ifndef ORDEREDINSERTER_H
#define ORDEREDINSERTER_H

#include <string>
#include <vector>

#include "Company.h"

class OrderedInserter {
public:
    OrderedInserter(std::vector<const Company*>& companies)
        : _companies(companies) {}

    void insert(const Company* company) {
        auto itC = _companies.begin();
        while (itC != _companies.end() && (*itC)->getId() < company->getId()) {
            itC++;   
        }
        _companies.insert(itC, company);
    }

private:
    std::vector<const Company*>& _companies;
};

#endif // !ORDEREDINSERTER_H
