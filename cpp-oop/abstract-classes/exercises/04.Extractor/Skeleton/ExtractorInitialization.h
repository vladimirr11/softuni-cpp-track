#ifndef EXTRACTORINITIALIZATION_H
#define EXTRACTORINITIALIZATION_H

#include <iostream>

#include "BufferedExtractor.h"
#include "DigitsExtractor.h"
#include "NumberExtractor.h"
#include "QuotesExtractor.h"

std::shared_ptr<Extractor> getExtractor(const std::string& extractType, std::istringstream& inputStream) {
    if (extractType == "digits") {
        return std::make_shared<DigitsExtractor>(inputStream);
    }

    if (extractType == "numbers") {
        return std::make_shared<NumberExtractor>(inputStream);
    }

    if (extractType == "quotes") {
        return std::make_shared<QuotesExtractor>(inputStream);
    }

    std::cerr << "Unsupported extractor: " << extractType << std::endl;
    return nullptr;
}

#endif // !EXTRACTORINITIALIZATION_H
