#ifndef FILTERFACTORY_H
#define FILTERFACTORY_H

#include <string>
#include "UppercaseFilter.h"
#include "LowercaseFilter.h"
#include "NumberFilter.h"

class Filter;

class FilterFactory {
public:
    FilterFactory() = default;

    Filter* buildFilter(const std::string& definition) const {
        if (definition == "A-Z") {
            return new UppercaseFilter('A', 'Z');
        }

        if (definition == "a-z") {
            return new LowercaseFilter('a', 'z');
        }

        if (definition == "0-9") {
            return new NumberFilter('0', '9');
        }

        return nullptr;
    }

};

#endif // !FILTERFACTORY_H
