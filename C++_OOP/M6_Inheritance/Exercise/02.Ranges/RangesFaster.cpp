#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <memory>
#include <algorithm>

class Ranges {
public:
    Ranges() : _from(0), _to(0) {};

    Ranges(int from, int to) : _from(from), _to(to) {}

    int getFrom() const {
        return _from;
    }

    int getTo() const {
        return _to;
    }

private:
    int _from;
    int _to;
};

bool inRange(int currInt, std::map<int, std::shared_ptr<Ranges>>& fromRangesMap,
                          std::map<int, std::shared_ptr<Ranges>>& toRangesMap) {
    
    auto fromIt = fromRangesMap.upper_bound(currInt); /// find first range start higher than value
    if (fromIt == fromRangesMap.begin()) {
        return false; /// no range starting before currInt
    }

    fromIt--; /// go back to the first range that starts at or before currInt

    auto toIt = toRangesMap.lower_bound(currInt);
    if (toIt == fromRangesMap.end()) {
        return false; /// no range ending at or after currInt
    }

    /// if both iterators point to the same range, then currInt is inside that range
    return fromIt->second == toIt->second;
}

int main() {
    std::map<int, std::shared_ptr<Ranges>> fromRangesMap;
    std::map<int, std::shared_ptr<Ranges>> toRangesMap;

    std::string inputRange;
    while (getline(std::cin, inputRange) && inputRange != ".") {
        std::istringstream istr(inputRange);

        int from = 0, to = 0;
        istr >> from >> to;

        std::shared_ptr<Ranges> currRange = std::make_shared<Ranges>(from, to);

        fromRangesMap[from] = currRange;
        toRangesMap[to] = currRange;
    }

    std::string inputInt;
    std::ostringstream output;
    while (getline(std::cin, inputInt) && inputInt != ".") {
        std::istringstream istr(inputInt);
        int currInt = 0;
        istr >> currInt;

        if (inRange(currInt, fromRangesMap, toRangesMap)) {
            output << "in" << "\n";
        } else {
            output << "out" << "\n";
        }
    }

    std::cout << output.str() << std::endl;

    return 0;
}
