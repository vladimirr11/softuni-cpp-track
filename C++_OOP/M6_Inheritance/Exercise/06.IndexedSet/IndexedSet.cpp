#include "IndexedSet.h"

#include <algorithm>

IndexedSet::IndexedSet() : valuesSet(), valuesArray(nullptr) {}

IndexedSet::IndexedSet(const IndexedSet& other) : valuesSet(other.valuesSet), valuesArray(nullptr) {
    if (other.valuesArray) {
        const size_t size = other.valuesSet.size();
        valuesArray = new Value[size];
        std::copy(other.valuesArray, other.valuesArray + size, valuesArray);
    }
}

IndexedSet& IndexedSet::operator=(const IndexedSet& other) {
    if (this != &other) {
        clearIndex();

        valuesSet = other.valuesSet;
        if (!valuesSet.empty()) {
            buildIndex();
        }
    }

    return *this;
}

IndexedSet::~IndexedSet() {
    clearIndex();
}

void IndexedSet::add(const Value& v) {
    clearIndex();
    valuesSet.insert(v);
}

size_t IndexedSet::size() const {
    return valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index) {
    if (!valuesArray) {
        buildIndex();
    }

    return valuesArray[index];
}

void IndexedSet::buildIndex() {
    const size_t size = valuesSet.size();
    valuesArray = new Value[size];

    int idx = 0;
    for (const auto value : valuesSet) {
        valuesArray[idx] = value;
        idx++;
    }
}

void IndexedSet::clearIndex() {
    if (valuesArray) {
        delete[] valuesArray;
        valuesArray = nullptr;
    }
}
