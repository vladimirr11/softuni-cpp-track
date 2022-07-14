#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <string>
#include <vector>

typedef std::vector<std::string> vecOfStrings;

vecOfStrings operator+(const vecOfStrings& vec1, const vecOfStrings& vec2) {
    vecOfStrings resultVec;
    
    const size_t lengthOfVecs = vec1.size();
    for (size_t i = 0; i < lengthOfVecs; i++) {
        std::string currIterResult = vec1[i] + " " + vec2[i];
        resultVec.push_back(currIterResult);
    }

    return resultVec;
}

#endif // !SUMOFVECTORS_H
