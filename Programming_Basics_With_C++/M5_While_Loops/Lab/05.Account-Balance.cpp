#include <iostream>
#include <string>

using namespace std;

int main() {
    int numDeposits;
    cin >> numDeposits; 

    int counter = 1;
    double deposit, totalSum = 0;

    cout.setf(ios::fixed);
    cout.precision(2);

    while (counter <= numDeposits) {
        counter += 1;
        cin >> deposit;
        if (deposit < 0) {
            cout << "Invalid operation!" << endl;
            break;
        }
        cout << "Increase: " << deposit << endl;
        totalSum += deposit;
    }

    cout << "Total: " << totalSum << endl;

    return 0;
}
