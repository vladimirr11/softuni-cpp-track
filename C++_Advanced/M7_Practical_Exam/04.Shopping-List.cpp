#include <iostream>
#include <array>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <tuple>

typedef std::pair<std::string, double> pair;
using ShoppingCart = std::vector<pair>;

std::tuple<double, ShoppingCart> readInput() {
    int numItems {};
    std::cin >> numItems;
    std::cin.ignore();

    ShoppingCart cartVec;

    double totalPrice {};
    for (int i = 0; i < numItems; i++) {
        std::string itemName;
        std::getline(std::cin >> std::ws, itemName);
        std::string itemPrice;
        std::getline(std::cin >> std::ws, itemPrice);
        std::string itemCount;
        std::getline(std::cin >> std::ws, itemCount);

        double currItemPrice = std::stod(itemPrice) * std::stod(itemCount);
        cartVec.push_back(std::make_pair(itemName, currItemPrice));
        totalPrice += currItemPrice;
    }

    return std::make_tuple(totalPrice, cartVec);
}

void sortShoppingCart(ShoppingCart& cart) {
    std::sort(cart.begin(), cart.end(), [](pair& l, pair& r) {
        if (l.second != r.second) {
            return l.second > r.second;
        }

        return l.first < r.first;
    });
} 

void printShoppingCart(const ShoppingCart& cart) {
    for (const auto& p : cart) {
        std::cout << p.first << " " << p.second << std::endl;
    }
}

int main() {
    auto myTuple = readInput();

    double price = std::get<0>(myTuple);
    ShoppingCart cartVec = std::get<1>(myTuple);

    std::cout << "The total sum is: " << price << " lv." << std::endl;

    sortShoppingCart(cartVec);

    printShoppingCart(cartVec);

    return 0;
}
