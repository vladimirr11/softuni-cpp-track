#ifndef REMOVEINVALID_H
#define REMOVEINVALID_H

#include <list>
#include "Company.h"

void removeInvalid(std::list<Company*>& companies) {
    std::list<Company*>::iterator it;
    for (it = companies.begin(); it != companies.end(); it++) {
        Company* c = *it;
        if (c->getId() < 0) {
            delete c;
            it = companies.erase(it);
            it--;
        }
    }
}

#endif // !REMOVEINVALID_H
