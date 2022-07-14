// #include "Scientist.cpp"
#include "Scientist.h"
// #include "Discovery.cpp"
#include "Discovery.h"

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    int numScientist = 0;
    std::cin >> numScientist;

    std::vector<Discovery*> discoveriesVec;

    for (int i = 0; i < numScientist; i++) {
        std::string scientistName;
        int numDiscoveries = 0;
        std::cin >> scientistName >> numDiscoveries;
        std::cin.ignore();

        Scientist* s = new Scientist(const_cast<char*>(scientistName.c_str()), numDiscoveries);

        for (int j = 0; j < numDiscoveries; j++) {
            std::string line;
            getline(std::cin, line);

            std::istringstream istr(line);

            std::string discName;
            int year = 0;
            std::string field;

            istr >> discName >> year >> field;

            Fields f;

            if (field == "Physics") {
                f = Physics;
            } else if (field == "Chemistry") {
                f = Chemistry;
            } else if (field == "Linguistics") {
                f = Linguistics;
            } else if (field == "Philosophy") {
                f = Philosophy;
            }
            
        
            Discovery* d = new Discovery(discName.c_str(), year, *s, f);

            Discovery* dCopy = new Discovery(*d);

            discoveriesVec.push_back(dCopy);
        }
    }

    std::sort(discoveriesVec.begin(), discoveriesVec.end(), [](const Discovery* d1, const Discovery* d2) {
        return (*d1).getYear() < (*d2).getYear();
    });

    for (const auto& d : discoveriesVec) {
        std::cout << (*d).getDiscoveryName() << " - " << (*d).getScientistName() << " - " << (*d).getFieldOfStudy() << std::endl;
    }

    return 0;
}
