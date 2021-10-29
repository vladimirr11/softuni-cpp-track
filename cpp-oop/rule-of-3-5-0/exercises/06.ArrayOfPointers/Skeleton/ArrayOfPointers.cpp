#include "ArrayOfPointers.h"

void ArrayOfPointers::add(Company* c) {
    this->_pointers.push_back(std::shared_ptr<Company>(c));
}

size_t ArrayOfPointers::getSize() const {
    return this->_pointers.size();
}

Company* ArrayOfPointers::get(int index) const {
    return this->_pointers.at(index).get();
}
