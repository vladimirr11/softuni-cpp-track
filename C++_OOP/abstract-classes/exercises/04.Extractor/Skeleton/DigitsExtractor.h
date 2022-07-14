#ifndef DIGITSEXTRACTOR_H
#define DIGITSEXTRACTOR_H

#include "Extractor.h"
#include <iostream>

class DigitsExtractor : public Extractor {
public:
    DigitsExtractor(std::istream& stream) : Extractor(stream) {}

    bool process(char symbol, std::string& output) override {
		if (isdigit(symbol)) {
			output = symbol;
			return true;
		}
		else {
			return false;
		}
	}

private:

};

#endif // !DIGITSEXTRACTOR_H
