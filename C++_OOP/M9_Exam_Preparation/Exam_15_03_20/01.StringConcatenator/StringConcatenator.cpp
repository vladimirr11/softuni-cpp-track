#include "StringConcatenator.h"

StringConcatenator::StringConcatenator() {}

StringConcatenator::~StringConcatenator() {}

std::string StringConcatenator::concatenate(const ConcatenateStrategy strategy,
                                            const char* left, const size_t leftSize,
                                            const char* right, const size_t rightSize) const {

    std::string leftStr = left;
    std::string rightStr = right;

    std::string resultingStr;
    if (strategy == ConcatenateStrategy::LEFT_1_RIGHT_1) {
        if (leftSize == rightSize) {
            for (size_t i = 0; i < leftSize && i < rightSize; i++) {
                resultingStr.push_back(leftStr[i]);
                resultingStr.push_back(rightStr[i]);
            }
        }
        else if (leftSize < rightSize) {
            size_t sizeDiff = rightSize - leftSize;
            for (size_t i = 0; i < leftSize && i < rightSize; i++) {
                resultingStr.push_back(leftStr[i]);
                resultingStr.push_back(rightStr[i]);
            }

            resultingStr.append(rightStr.substr(rightSize - sizeDiff));
        }
        else if (leftSize > rightSize) {
            size_t sizeDiff = leftSize - rightSize;
            for (size_t i = 0; i < leftSize && i < rightSize; i++) {
                resultingStr.push_back(leftStr[i]);
                resultingStr.push_back(rightStr[i]);
            }

            resultingStr.append(rightStr.substr(leftSize - sizeDiff));
        }
    }
    else if (strategy == ConcatenateStrategy::LEFT_2_RIGHT_1) {
        if (leftSize == rightSize) {
            for (size_t i = 0; i < leftSize; i++) {
                if (i > 0 && i % 2 == 0) {
                    resultingStr.push_back(rightStr[(i / 2) - 1]);
                }
                resultingStr.push_back(leftStr[i]);
            }

            resultingStr.append(rightStr.substr((leftSize / 2) - 1));
        }
        else if (leftSize < rightSize) {
            for (size_t i = 0; i < leftSize; i++) {
                if (i > 0 && i % 2 == 0) {
                    resultingStr.push_back(rightStr[(i / 2) - 1]);
                }
                resultingStr.push_back(leftStr[i]);
            }

            resultingStr.append(rightStr.substr((leftSize / 2) - 1));
        }
        else if (leftSize > rightSize) {
            for (size_t i = 0; i < leftSize; i++) {
                if (i > 0 && i % 2 == 0) {
                    resultingStr.push_back(rightStr[(i / 2) - 1]);
                }
                resultingStr.push_back(leftStr[i]);
            }

            resultingStr.append(rightStr.substr((leftSize / 2) - 1));
        }
    }
    else if (strategy == ConcatenateStrategy::LEFT_1_RIGHT_2) {
        if (leftSize == rightSize) {
            for (size_t i = 0; i < rightSize; i++) {
                if (i == 0) {
                    resultingStr.push_back(leftStr[i]);
                    resultingStr.push_back(rightStr[i]);
                    continue;
                }
                if (i > 0 && i % 2 == 0) {
                    resultingStr.push_back(leftStr[(i / 2)]);
                }
                resultingStr.push_back(rightStr[i]);
            }

            resultingStr.append(leftStr.substr(rightSize / 2));
        }
        else if (leftSize > rightSize) {
            for (size_t i = 0; i < leftSize; i++) {
                if (i > 0 && i % 2 == 0) {
                    resultingStr.push_back(rightStr[(i / 2) - 1]);
                }
                resultingStr.push_back(leftStr[i]);
            }

            resultingStr.append(rightStr.substr((leftSize / 2) - 1));
        }
        else if (leftSize < rightSize) {
            for (size_t i = 0; i < leftSize; i++) {
                if (i > 0 && i % 2 == 0) {
                    resultingStr.push_back(rightStr[(i / 2) - 1]);
                }
                resultingStr.push_back(leftStr[i]);
            }

            resultingStr.append(rightStr.substr((leftSize / 2) - 1));
        }
    }

    return resultingStr;
}
