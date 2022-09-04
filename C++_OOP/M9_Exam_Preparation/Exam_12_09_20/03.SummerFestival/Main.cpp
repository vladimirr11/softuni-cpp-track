#include "Food.h"
#include "Order.h"

#include <sstream>

int main() {
    int numCommands = 0;
    std::cin >> numCommands;
    std::cin.ignore();

    Food food;
    for (int i = 0; i < numCommands; i++) {
        std::string line;

        getline(std::cin, line);
        std::istringstream istr(line);

        std::string command;
        istr >> command;
        if (command == "cook") {
            std::string type;
            std::string size;
            double price;

            istr >> type >> size >> price;
            food.cook(type, size, price);
        } else if (command == "sell") {
            int idx = 0;
            istr >> idx;

            food.sell(idx);
        } else if (command == "copy") {
            int idx1, idx2;

            istr >> idx1 >> idx2;
            food.copy(idx1, idx2);
        }
    }

    return 0;
}