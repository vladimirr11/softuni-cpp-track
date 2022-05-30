#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string month;
    int hours, people;
    string dayTime;

    cin >> month >> hours >> people >> dayTime;

    double pricePerson = 0.0;

    if (month == "march" || month == "april" || month == "may") {
        if (dayTime == "day") {
            if (people >= 4) {
                pricePerson = 10.5 * 0.9;
            } else {
                pricePerson = 10.5;
            }
        } else if (dayTime == "night") {
            if (people >= 4) {
                pricePerson = 8.4 * 0.9;
            } else {
                pricePerson = 10.5;
            }
        }
    } else if (month == "june" || month == "july" || month == "august") {
        if (dayTime == "day") {
            if (people >= 4) {
                pricePerson = 12.6 * 0.9;
            } else {
                pricePerson = 12.6;
            }
        } else if (dayTime == "night") {
            if (people >= 4) {
                pricePerson = 10.2 * 0.9;
            } else {
                pricePerson = 10.2;
            }
        }

    }

    if (hours >= 5) {
        pricePerson *= 0.5;
    }

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "Price per person for one hour: " << pricePerson << endl;
    cout << "Total cost of the visit: " << pricePerson * hours * people << endl;

    return 0;
}
