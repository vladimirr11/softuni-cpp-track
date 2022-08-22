#ifndef NUMBEREXTRACTOR_H
#define NUMBEREXTRACTOR_H

#include "BufferedExtractor.h"

class NumberExtractor : public BufferedExtractor {
public:
    NumberExtractor(std::istream& stream) : BufferedExtractor(stream) {}

protected:
    bool shouldBuffer(char symbol) override {
        return isdigit(symbol);
    }
};

#endif // !NUMBEREXTRACTOR_H
