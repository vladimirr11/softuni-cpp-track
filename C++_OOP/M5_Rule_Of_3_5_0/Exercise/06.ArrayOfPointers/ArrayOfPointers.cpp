#include "ArrayOfPointers.h"

void ArrayOfPointers::add(Company* c) {
    _pointers.push_back(std::shared_ptr<Company>(c));
}

size_t ArrayOfPointers::getSize() const {
    return _pointers.size();
}

Company* ArrayOfPointers::get(int index) const {
    return _pointers.at(index).get();
}
