#ifndef TYPEDSTREAM_H
#define TYPEDSTREAM_H

#include "Vector2D.h"

#include <vector>
#include <string>
#include <iostream>

template<typename T>
class TypedStream {
public:
    TypedStream() = default;

    TypedStream(const std::string& input) : stream(input) {}

    virtual ~TypedStream() = default;

    std::vector<T> readToEnd() {
        std::vector<T> elements;
        T elem;
        operator>>(elem);
        while (stream) {
            elements.push_back(elem);
            operator>>(elem);
        }

        return elements;
    }

    virtual TypedStream<T>& operator>>(T& in) {
        return *this;
    }

protected:
    std::istringstream stream;
};

#endif // !TYPEDSTREAM_H
