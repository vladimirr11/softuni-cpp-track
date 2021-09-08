#include <iostream>
#include <cmath>

using namespace std;


int main() {

    int lillyAge, priceToy;  
    double priceWashinMachine;
    cin >> lillyAge >> priceWashinMachine >> priceToy;

    int counter = 0;
    double gatheredSum;

    for (int i = 1; i <= lillyAge; i++) {
        if (i % 2 == 0) {
            counter += 1;
            gatheredSum += counter * 10;
        } else {
            gatheredSum += priceToy;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(2);

    if (gatheredSum - counter >= priceWashinMachine) {
        cout << "Yes! " << (gatheredSum - counter) - priceWashinMachine << endl;
    } else {
        cout << "No! " << priceWashinMachine - (gatheredSum - counter) << endl;
    }

    return 0;
}