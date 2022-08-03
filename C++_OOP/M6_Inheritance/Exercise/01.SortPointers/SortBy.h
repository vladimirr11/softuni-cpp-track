#ifndef SORTBY_H
#define SORTBY_H

#include <algorithm>

void sortBy(Company** start, Company** end, bool (&funcLessThanCallback)(const Company&, const Company&)) {
    std::sort(start, end, [&](const Company* const &a, const Company* const &b){ 
        return funcLessThanCallback(*a, *b);
    });
}

#endif // !SORTBY_H
