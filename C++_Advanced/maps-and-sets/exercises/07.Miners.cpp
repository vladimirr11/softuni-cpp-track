#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

std::unordered_map<std::string, int> getInput() {
    std::unordered_map<std::string, int> resourceQauntityMap = {};

    while (true) {
        std::string resource;
        int quantity = 0;

        std::cin >> resource;
        if (resource == "stop") {
            break;
        }

        std::cin >> quantity;

        resourceQauntityMap[resource] += quantity;
    }

    return resourceQauntityMap;
}

int main() {
    std::unordered_map<std::string, int> resourceQauntityMap = getInput();

    for (const auto& resourceIt : resourceQauntityMap) {
        std::cout << resourceIt.first << " -> " << resourceIt.second << std::endl;
    }

    return 0;
}
