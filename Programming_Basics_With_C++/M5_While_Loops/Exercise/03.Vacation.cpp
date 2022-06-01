#include <iostream>
#include <string>

using namespace std;

int main() {
    double neededMoney, possessedMoney, totalSpendedMoney = 0.00;
    int counterSpending = 0, counterDays = 0;

    cin >> neededMoney >> possessedMoney;

    cin.ignore();

    while (true) {
        string action;
        getline(cin, action);

        double money;
        cin >> money;

        totalSpendedMoney += money;
        counterDays++;

        cin.ignore();

        if (action == "spend") {
            counterSpending++;
            possessedMoney -= money;
            if (possessedMoney < 0) {
                possessedMoney = 0;
            }
        } else {
            possessedMoney += money;
            if (possessedMoney >= neededMoney) {
                cout << "You saved the money for "<< counterDays << " days." << endl;
                break;
            }
            counterSpending = 0;
        }

        if (counterSpending == 5) {
            cout << "You can't save the money." << endl << counterDays << endl;
            break;
        }

    }

    return 0;
}
