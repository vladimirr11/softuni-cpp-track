#include <iostream>

using namespace std;


int main() {

    double budget;
    int numWorkers;
    double priceCostumes;
    
    cin >> budget >> numWorkers >> priceCostumes;

    double priceStage = budget * 0.1;

    cout.setf(ios::fixed);
    cout.precision(2);

    if (numWorkers > 150) {
        priceCostumes *= 0.9;
    }

    if ((priceCostumes * numWorkers) + priceStage > budget) {
        cout << "Not enough money!" << endl << "Wingard needs " <<
        ((priceCostumes * numWorkers) + priceStage) - budget << " leva more." << endl;
    } else {
        cout << "Action!" << endl << "Wingard starts filming with " << 
        budget - (priceStage + (priceCostumes * numWorkers)) << " leva left." << endl;
    }

    return 0;
}