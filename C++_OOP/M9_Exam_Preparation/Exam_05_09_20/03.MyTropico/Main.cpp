#include "Tropico.h"
#include "Building.h"
#include "Palace.h"
#include "House.h"

#include "Tropico.h"
#include "Building.h"
#include "Palace.h"
#include "House.h"

#include <sstream>

int main() {
    int numCommands = 0;
    std::cin >> numCommands;
    std::cin.ignore();

    Tropico tropico;

    for (int i = 0; i < numCommands; i++) {
        std::string line;
        getline(std::cin, line);

        std::istringstream istr(line);

        std::string command;
        istr >> command;
        if (command == "build") {
            std::string buildingType;
            int width = 0, length = 0;

            istr >> buildingType >> width >> length;
            
            tropico.build(buildingType, width, length);

        } else if (command == "replace") {
            int idx1 = 0, idx2 = 0;
            istr >> idx1 >> idx2;

            tropico.replace(idx1, idx2);

        } else if (command == "duplicate") {
            int idx1 = 0, idx2 = 0;
            istr >> idx1 >> idx2;

            tropico.duplicate(idx1, idx2);
        } else if (command == "demolish") { 
            int idx1 = 0;
            istr >> idx1;

            tropico.demolish(idx1);
        }
    }

    return 0;
}
