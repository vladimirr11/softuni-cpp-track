#ifndef SUMAGGREGATOR_H
#define SUMAGGREGATOR_H

#include "Aggregator.h"

class SumAggregator : public StreamAggregator {
public:
    SumAggregator(std::istream& istr) : StreamAggregator(istr) {
        aggregationResult = 0;
    }

    void aggregate(int next) override {
        StreamAggregator::aggregate(next);
        aggregationResult += next;
    }

    ~SumAggregator() = default;
};

#endif // !SUMAGGREGATOR_H
