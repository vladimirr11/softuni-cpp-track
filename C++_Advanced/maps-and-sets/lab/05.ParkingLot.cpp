#include <iostream>
#include <set>
#include <string>
#include <sstream>

std::set<std::string> getParkingInOutTraffic() {
    std::set<std::string> carNumbers = {};

    std::string inOut;
    std::string carNumber;

    while (true) {
        std::string iLine;
        getline(std::cin, iLine);
        std::istringstream iStream(iLine);

        iStream >> inOut;
        if (inOut == "END") {
            break;
        }
        
        iStream >> carNumber;
        
        if (inOut == "IN,") {
            carNumbers.insert(carNumber);
        } else if (inOut == "OUT,") {
            carNumbers.erase(carNumber);
        }
    }

    return carNumbers;
}

int main() {
    std::set<std::string> carNumbers = getParkingInOutTraffic();

    std::set<std::string>::iterator carNumsIt;
    for (carNumsIt = carNumbers.begin(); carNumsIt != carNumbers.end(); carNumsIt++) {
        std::cout << *carNumsIt << std::endl;
    }

    return 0;
}
