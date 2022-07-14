#ifndef NUMBEREXTRACTOR_H
#define NUMBEREXTRACTOR_H

#include "BufferedExtractor.h"

class NumberExtractor : public BufferedExtractor {
public:
    NumberExtractor(std::istream& stream) : BufferedExtractor(stream), isNumber(false) {}

protected:
    bool shouldBuffer(char symbol) override {
		return isNumber = isdigit(symbol);
	}

private:
    bool isNumber;
};

#endif // !NUMBEREXTRACTOR_H
