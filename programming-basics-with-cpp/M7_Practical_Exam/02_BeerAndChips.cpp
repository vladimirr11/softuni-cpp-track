#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string name;
    double budget;
    int numBeers, numChips;

    cin >> name >> budget >> numBeers >> numChips;

    double sumBeers = numBeers * 1.2;

    double chipPrice = (sumBeers * 0.45) * numChips;

    double priceChips = ceil(chipPrice);

    double totalSum = sumBeers + priceChips;
    
    cout.setf(ios::fixed);
    cout.precision(2);

    if (budget >= totalSum) {
        cout << name << " bought a snack and has " << budget - totalSum << " leva left." << endl;
    } else {
        cout << name << " needs " << totalSum - budget << " more leva!" << endl;
    }

    return 0;
}
