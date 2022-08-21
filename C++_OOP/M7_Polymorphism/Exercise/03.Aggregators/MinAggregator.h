#ifndef MINAGGREGATOR_H
#define MINAGGREGATOR_H

#include "Aggregator.h"

#include <limits>

class MinAggregator : public StreamAggregator {
public:
    MinAggregator(std::istream& istr) : StreamAggregator(istr) {
        aggregationResult = std::numeric_limits<int>::max();
    }

    void aggregate(int next) override {
        StreamAggregator::aggregate(next);
        
        if (next < aggregationResult) {
            aggregationResult = next;
        }
    }

    ~MinAggregator() = default;
};

#endif // !MINAGGREGATOR_H
