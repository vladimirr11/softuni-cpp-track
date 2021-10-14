#include <iostream>
#include <string>
#include <sstream>
#include <map>

typedef std::map<std::string, double> sales;

class Sale {
public:
    Sale() : townSales {}, _price(0), _quantity(0) {}

    void readInputData() {
        int numRecords = 0;
        std::cin >> numRecords;
        std::cin.ignore();

        for (int i = 0; i < numRecords; i++) {
            std::string line;
            getline(std::cin, line);

            std::istringstream istr(line);
            istr >> _town >> _product >> _price >> _quantity;

            townSales[_town] += (_price * _quantity);
        }
    }

    void printTownSales() {
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        for (const auto& town : townSales) {
            std::cout << town.first << " -> " << town.second << std::endl;
        }
    }

private:
    sales townSales;

    std::string _town;
    std::string _product;

    double _price;
    double _quantity;
};

int main() {
    Sale townSales;

    townSales.readInputData();
    
    townSales.printTownSales();

    return 0;
}
