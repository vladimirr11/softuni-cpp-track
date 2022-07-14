#include "FixedArray.h"

FixedArray::FixedArray(const int arraySize) : BrokenArray(arraySize) {}

FixedArray::~FixedArray() { 
    if (this->_array) {
        delete[] _array;
        _array = nullptr;
    }
}

FixedArray::FixedArray(const FixedArray &other) : BrokenArray(other.getSize()) {
    for (size_t i = 0; i < other.getSize(); i++) {
        _array[i] = other._array[i];
    }
}

FixedArray& FixedArray::operator=(const FixedArray &other) {
    if (this != &other) {
        int* newArray = new int[other.getSize()];

        for (int i = 0; i < other.getSize(); i++) {
            newArray[i] = other._array[i];
        }

        if (_array) {
            delete[] _array;
            _array = nullptr;
        }
        
        this->_array = newArray;
        newArray = nullptr;
    }

    return *this;
}

void FixedArray::addValueToMemory(const int value) {
    BrokenArray::addValueToMemory(value);
}

int FixedArray::getMemorySumValue() const {
   return BrokenArray::getMemorySumValue();
}
