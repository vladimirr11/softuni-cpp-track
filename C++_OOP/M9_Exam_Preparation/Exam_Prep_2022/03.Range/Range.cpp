#include "Range.h"

#include <limits>

Range::Range() 
    : rangeFirst(0), rangeLength(0), valueCounts(nullptr) {}

void Range::add(T value) {
    if (empty()) {
        resize(value, 1);
    } else if (value < rangeFirst) {
        resize(value, rangeLength + rangeFirst - value);
    } else if ((rangeFirst + rangeLength) <= value) {
        resize(rangeFirst, value - rangeFirst + 1);
    }

    valueCounts[value - rangeFirst]++;
}

size_t Range::getCount(T value) const {
    if (rangeFirst <= value && value <= (rangeFirst + rangeLength))
        return valueCounts[value - rangeFirst];
    return 0;
}

void Range::clear() {
    if (valueCounts) {
        rangeFirst = 0;
        rangeLength = 0;
        delete[] valueCounts;
        valueCounts =  nullptr;
    }
}

void Range::resize(T first, T last) {
    size_t* newValuesCount = new size_t[last]{};
    if (valueCounts) {
        memcpy(newValuesCount + (rangeFirst - first), valueCounts, sizeof(size_t) * rangeLength);
        clear();
    }

    rangeFirst = first;
    rangeLength = last;
    valueCounts = newValuesCount;
}

bool Range::empty() const {
    return valueCounts == nullptr;
}

Range::Range(const Range& other) : rangeFirst(other.rangeFirst), rangeLength(other.rangeLength) {
    if (other.empty())
        valueCounts = nullptr;
    else {
        valueCounts = copyValues(other);
    }
}

Range& Range::operator=(const Range& other) {
    if (this != &other) {
        clear();
        rangeFirst = other.rangeFirst;
        rangeLength = other.rangeLength;
        valueCounts = copyValues(other);
    }

    return *this;
}

Range::~Range() {
    clear();
}
