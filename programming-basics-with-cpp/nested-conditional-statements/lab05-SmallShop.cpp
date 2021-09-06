#include <iostream>
#include <string>

using namespace std;


int main() {

    // град/продукт coffee water beer sweets peanuts
    // Sofia          0.50  0.80  1.20 1.45   1.60
    // Plovdiv        0.40  0.70  1.15 1.30   1.50
    // Varna          0.45  0.70  1.10 1.35   1.55
    
    string product, city;
    double quantity;
    cin >> product >> city >> quantity;

    double price;

    if (product == "coffee" && city == "Sofia") {
        price = 0.50;
    } else if (product == "coffee" && city == "Plovdiv") {
        price = 0.40;
    } else if (product == "coffee" && city == "Varna") {
        price = 0.45;
    } else if (product == "water" && city == "Sofia") {
        price = 0.80;
    } else if (product == "water" && city == "Plovdiv") {
        price = 0.70;
    } else if (product == "water" && city == "Varna") {
        price = 0.70;
    } else if (product == "beer" && city == "Sofia") {
        price = 1.20;
    } else if (product == "beer" && city == "Plovdiv") {
        price = 1.15;
    } else if (product == "beer" && city == "Varna") {
        price = 1.10;
    } else if (product == "sweets" && city == "Sofia") {
        price = 1.40;
    } else if (product == "sweets" && city == "Plovdiv") {
        price = 1.30;
    } else if (product == "sweets" && city == "Varna") {
        price = 1.35;
    } else if (product == "peanuts" && city == "Sofia") {
        price = 1.60;
    } else if (product == "peanuts" && city == "Plovdiv") {
        price = 1.50;
    } else if (product == "peanuts" && city == "Varna") {
        price = 1.55;
    }

    cout << quantity * price << endl;
    
    return 0;
}