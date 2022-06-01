#include <iostream>

using namespace std;

int main() {
    int numDays, numBakers, numCakes, numWaffles, numPanckes;
    cin >> numDays >> numBakers >> numCakes >> numWaffles >> numPanckes;

    double earnMoney = numDays * (numBakers * ((numCakes * 45) + (numWaffles * 5.8) + (numPanckes * 3.2)));
    
    double moneyWithoutExpences = earnMoney - (earnMoney / 8);

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << moneyWithoutExpences << endl;

    return 0;
}
