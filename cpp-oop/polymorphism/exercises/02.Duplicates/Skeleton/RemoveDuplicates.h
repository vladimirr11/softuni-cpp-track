#ifndef REMOVEDUPLICATES_H
#define REMOVEDUPLICATES_H

#include <list>
#include <set>
#include <algorithm>

#include "Company.h"

void removeDuplicates(std::list<Company*>& companies){
    std::set<Company*> companiesSet;

    std::list<Company*>::iterator it;
    for (it = companies.begin(); it != companies.end(); it++) {
        bool isUniqueObj = true;

        if (companiesSet.find(*it) != companiesSet.end()) {
            isUniqueObj = false;

            it = companies.erase(it);
        }

        if (isUniqueObj) {
            companiesSet.insert(*it);
            it = companies.erase(it);
        }
    }

    for (const auto& c : companiesSet) {
        companies.push_back(c);
    }

}

#endif // !REMOVEDUPLICATES_H
