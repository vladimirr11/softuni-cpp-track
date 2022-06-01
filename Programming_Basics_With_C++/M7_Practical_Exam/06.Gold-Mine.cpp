#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int locations;
    cin >> locations;

    cout.setf(ios::fixed);
    cout.precision(2);

    for (int i = 1; i <= locations; i++) {
        double expectedGold;
        int days;
        cin >> expectedGold >> days;

        double gold = 0.0;
        for (int j = 1; j <= days; j++) {
            double goldPerDay;
            cin >> goldPerDay;
            gold += goldPerDay;
        }

        double averageGold = gold / days;
        if (averageGold >= expectedGold) {
            cout << "Good job! Average gold per day: " << averageGold << "." << endl;
        } else {
            cout << "You need " << expectedGold - averageGold << " gold." << endl;
        }
    }

    return 0;
}
