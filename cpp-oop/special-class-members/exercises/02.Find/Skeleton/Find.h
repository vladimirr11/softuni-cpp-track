#ifndef FIND_H
#define FIND_H

#include <vector>

#include "Company.h"

Company* find(const std::vector<Company*>& companies, int searchId) {
    for (Company* company : companies) {
        if (company->getId() == searchId) {
            return company;
        }
    }

    return nullptr;
}

#endif // !FIND_H
