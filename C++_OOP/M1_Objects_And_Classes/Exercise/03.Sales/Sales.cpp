#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <map>

typedef std::map<std::string, double> sales;

class Sale {
public:
    Sale() : _townSales{}, _town{}, _product{}, _price{}, _quantity{} {}

    void readAndCalcSale();

    void printSales();

private:
    sales _townSales;

    std::string _town;
    std::string _product;

    double _price;
    double _quantity;
};

void Sale::readAndCalcSale(void) {
    std::string line;
    getline(std::cin, line);

    std::istringstream istr(line);
    istr >> _town >> _product >> _price >> _quantity;

    _townSales[_town] += (_price * _quantity);
}

void Sale::printSales() {
    std::cout.setf(std::ios::fixed);
    for (const auto& town : _townSales) {
        std::cout << std::setprecision(2) << town.first << " -> " << town.second << std::endl;
    }
}

int main() {
    int numRecords {};
    std::cin >> numRecords;
    std::cin.ignore();

    Sale* townSales = new Sale[numRecords];
    for (int i = 0; i < numRecords; i++) {
        townSales->readAndCalcSale();
    }

    townSales->printSales();

    delete[] townSales;

    return 0;
}
