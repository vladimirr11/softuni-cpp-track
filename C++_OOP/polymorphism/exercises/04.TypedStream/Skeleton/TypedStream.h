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
		std::vector<T> items;
		T item;
		this->operator>>(item);
		while (this->stream) {
			items.push_back(item);
			this->operator>>(item);
		}

		return items;
	}

    virtual TypedStream<T>& operator>>(T& in) {
        return *this;
    }

protected:
    std::istringstream stream;
};

#endif // !TYPEDSTREAM_H
