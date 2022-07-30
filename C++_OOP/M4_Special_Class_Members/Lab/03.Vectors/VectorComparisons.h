#ifndef VECTORCOMPARISONS_H
#define VECTORCOMPARISONS_H

#include "Vector.h"

class VectorLengthComparer {
public:
    bool operator()(const Vector& v1, const Vector& v2) const {
        return v1.getLength() > v2.getLength();
    }
};

template<typename Cont, typename LengthComp>
class ReverseComparer {
public:
    bool operator()(const Cont& c1, const Cont& c2) const {
        LengthComp comp;
        return comp(c1, c2);
    }
};

#endif // !VECTORCOMPARISONS_H
