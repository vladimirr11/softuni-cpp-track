#ifndef COMPARATORS_H
#define COMPARATORS_H

#include "Song.h"

template<typename Type>
class LessThan {
public:
    bool operator()(const Type& lhs, const Type& rhs) const {
        return lhs < rhs;
    }
};

template<>
class LessThan<Song> {
public:
    bool operator()(const Song& lhs, const Song& rhs) const {
        return lhs.getLengthSeconds() < rhs.getLengthSeconds();
    }
};

template<typename Type, typename Comparator>
class Reverse {
public:
    bool operator()(const Type& lhs, const Type& rhs) const {
        Comparator comp;
        return !comp(lhs, rhs);
    }
};

#endif // !COMPARATORS_H
