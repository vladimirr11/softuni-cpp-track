#include <iostream>
#include <set>
#include <string>
#include <sstream>

std::set<std::string> getInputLisOfNames() {
    int numPeople = 0;
    std::cin >> numPeople;

    std::set<std::string> inputList {};

    for (int i = 0; i < numPeople; i++) {
        std::string iLine;
        getline(std::cin, iLine);
        std::istringstream iStream(iLine);
        std::string person;
        iStream >> person;
        inputList.insert(person);
    }

    return inputList;
}

int main() {
    std::set<std::string> peopleList = getInputLisOfNames();

    std::set<std::string>::iterator peopleIt;
    for (peopleIt = peopleList.begin(); peopleIt != peopleList.end(); peopleIt++) {
        std::cout << *peopleIt << std::endl;
    }

    return 0;
}
