#ifndef ARRAYOFPOINTERS_H
#define ARRAYOFPOINTERS_H

#include <vector>
#include <memory>

#include "Company.h"

class ArrayOfPointers {
public:
    ArrayOfPointers() {};

    void add(Company* c);

    size_t getSize() const;

    Company* get(int index) const;

private:
    std::vector<std::shared_ptr<Company>> _pointers;
};

#endif // !ARRAYOFPOINTERS_H
