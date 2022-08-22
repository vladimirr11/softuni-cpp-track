#ifndef QUOTESEXTRACTOR_H
#define QUOTESEXTRACTOR_H

#include "BufferedExtractor.h"

class QuotesExtractor : public BufferedExtractor {
public:
    QuotesExtractor(std::istream& stream) : BufferedExtractor(stream), inQuotes(false) {}

    bool shouldBuffer(char symbol) override {
        if (inQuotes) {
            inQuotes = (symbol != '"');
            return inQuotes;
        } else {
            inQuotes = symbol == '"';
            return false;
        }
    }

private:
    bool inQuotes;
};

#endif // !QUOTESEXTRACTOR_H
