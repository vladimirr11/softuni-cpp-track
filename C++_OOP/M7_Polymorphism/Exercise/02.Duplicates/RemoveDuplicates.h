#ifndef REMOVEDUPLICATES_H
#define REMOVEDUPLICATES_H

#include <list>
#include <set>
#include <algorithm>

#include "Company.h"

void removeDuplicates(std::list<Company*>& companies){
    std::set<Company*> companiesSet;
    std::set<std::string> companiesNames;

    std::list<Company*>::iterator it;
    for (it = companies.begin(); it != companies.end();) {
        if (companiesSet.find(*it) != companiesSet.end()) {
            it = companies.erase(it);
        } else {
            if (companiesNames.find((*it)->getName()) != companiesNames.end())
                it = companies.erase(it);
            else {  
                companiesSet.insert(*it);
                companiesNames.insert((*it)->getName());
                it++;
            }
        }
    }
}

#endif // !REMOVEDUPLICATES_H
