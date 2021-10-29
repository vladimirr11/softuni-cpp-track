#include "Range.h"

#include <math.h>

Range::Range() : 
    rangeFirst(0), rangeLength(0), valueCounts(new size_t[10000]{}) {}

void Range::add(T value) {
    if (rangeLength == 0) {
        rangeFirst = value;
        rangeLength++;
        // valueCounts = new size_t[rangeLength]{};
        valueCounts[value]++;
    } else {
        if (value < rangeFirst) {
            rangeFirst = value;
            rangeLength = std::abs(rangeLength - rangeFirst);
            valueCounts[value]++;
            // size_t* resized = new size_t[rangeLength];

            // valueCounts = new size_t[rangeLength];
        } else if (value == rangeFirst) {
            valueCounts[value]++;
        } else if (value > rangeLength) {
            rangeLength = value - rangeFirst;
            // valueCounts = new size_t[rangeLength]{};
            valueCounts[value]++;
        }
    }
 }

size_t Range::getCount(T value) const {
    T queryValueCount = this->valueCounts[value];
    return queryValueCount;
}

// void Range::clear() {

// }

// void Range::resize(T first, T last) {

// }

bool Range::empty() const {
    return this->valueCounts != nullptr;
}

Range::Range(const Range& other) : 
    rangeFirst(other.rangeFirst), rangeLength(other.rangeLength), valueCounts(other.valueCounts) {

    for (size_t i = rangeFirst; i < rangeLength; i++) {
        this->valueCounts[i] = other.valueCounts[i];
    }
}

// Range& Range::operator=(const Range& other) {
//     if (this != &other) {
// 		copyValueCounts = new size_t[other.valueCounts];

// 	}

// 	return *this;
// }

// Range::~Range() {
//     if (valueCounts) {
//         delete[] valueCounts;
//         valueCounts = nullptr;
//     }
// }
