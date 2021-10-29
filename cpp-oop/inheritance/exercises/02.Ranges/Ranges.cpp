#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <algorithm>

class Ranges {
public:
    Ranges() : _from(0), _to(0) {};

    Ranges(int from, int to) : _from(from), _to(to) {}

    int getFrom() const {
        return this->_from;
    }

    int getTo() const {
        return this->_to;
    }

private:
    int _from;
    int _to;
};

std::vector<std::shared_ptr<Ranges>> readRanges() {
    std::vector<std::shared_ptr<Ranges>> ranges;
    ranges.reserve(10000);

    std::string inputRange;
    while (getline(std::cin, inputRange) && inputRange != ".") {
        std::istringstream istr(inputRange);

        int from = 0, to = 0;
        istr >> from >> to;

        std::shared_ptr<Ranges> rangePtr = std::make_shared<Ranges>(from, to);
        ranges.push_back(rangePtr);
    }

    return ranges;
}

bool inRange(std::vector<std::shared_ptr<Ranges>>& ranges, int currInt) {
    for (const auto& range : ranges) {
        if (range->getFrom() <= currInt && currInt <= range->getTo()) {
            return true;
        }
    }

    return false;
}

int main() {
    std::vector<std::shared_ptr<Ranges>> ranges = readRanges();

    std::string inputInt;
    std::ostringstream output;
    while (getline(std::cin, inputInt) && inputInt != ".") {
        std::istringstream istr(inputInt);
        int currInt = 0;
        istr >> currInt;

        if (inRange(ranges, currInt)) {
            output << "in" << "\n";
        } else {
            output << "out" << "\n";
        }
    }

    std::cout << output.str() << std::endl;

    return 0;
}
