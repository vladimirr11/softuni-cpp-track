#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using vec_map_tuple = std::tuple<std::vector<std::string>, std::unordered_map<std::string, int>>;

vec_map_tuple getInput() {
    std::vector<std::string> resourcesVec {};
    std::unordered_map<std::string, int> resourceQauntityMap {};

    while (true) {
        std::string resource;
        int quantity {};

        std::cin >> resource;
        if (resource == "stop") {
            break;
        }

        std::cin >> quantity;

        if (resourceQauntityMap.find(resource) == resourceQauntityMap.end()) {
            resourcesVec.push_back(resource);
        }
        resourceQauntityMap[resource] += quantity;
    }

    return std::make_tuple(resourcesVec, resourceQauntityMap);
}

int main() {
    vec_map_tuple myTuple = getInput();

    auto resourcesVec = std::get<0>(myTuple);
    auto resourceQauntityMap = std::get<1>(myTuple);

    for (const auto& res : resourcesVec) {
        std::cout << res << " -> " << resourceQauntityMap[res] << std::endl;
    }

    return 0;
}
