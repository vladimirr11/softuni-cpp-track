#include <iostream>
#include <string>

using namespace std;


int main() {

    string season;
    int budget, numFishermen;

    cin >> budget >> season >> numFishermen;

    double boatPrice;
    // double discount;

    if (season == "Summer" || season == "Autumn") {
        boatPrice = 4200;
    } else if (season == "Spring") {
        boatPrice = 3000;
    } else if (season == "Winter") {
        boatPrice = 2600;
    }

    if (numFishermen <= 6 ) {
        boatPrice *= 0.9;
    } else if (numFishermen >= 7 && numFishermen <= 11) {
        boatPrice *= 0.85;
    } else if (numFishermen >= 12) {
        boatPrice *= 0.75;
    }

    if (numFishermen % 2 == 0 && season != "Autumn") {
        boatPrice *= 0.95;
    }

    cout.setf(ios::fixed);
    cout.precision(2);

    if (budget > boatPrice) {
        cout << "Yes! You have " << budget - boatPrice << " leva left." << endl;
    } else {
        cout << "Not enough money! You need " << boatPrice - budget << " leva." << endl;
    }

    return 0;
}