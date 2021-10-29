#ifndef AVERAGEAGGREGATOR_H
#define AVERAGEAGGREGATOR_H

#include "Aggregator.h"

class AverageAggregator : public StreamAggregator {
public:
    AverageAggregator(std::istream& istr) : StreamAggregator(istr) {
        aggregationResult = 0;
    }

    void aggregate(int next) override {
        StreamAggregator::aggregate(next);

        _currSum += next;
        aggregationResult = _currSum / StreamAggregator::getNumAggregated();
	}

    ~AverageAggregator() = default;
    
protected:
    int _currSum = 0;
};

#endif // !AVERAGEAGGREGATOR_H
