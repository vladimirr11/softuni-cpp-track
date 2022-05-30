#include <iostream>
#include <string>

using namespace std;

int main() {
    double budget;
    string season, destination, vacationPlace;
    
    cin >> budget >> season;

    if (budget <= 100) {
        destination = "Bulgaria";
        if (season == "summer") {
            vacationPlace = "Camp";
            budget *= 0.30;
        } else {
            vacationPlace = "Hotel";
            budget *= 0.70;
        }
    } else if (budget > 100 && budget <= 1000) {
        destination = "Balkans";
        if (season == "summer") {
            vacationPlace = "Camp";
            budget *= 0.40;
        } else {
            vacationPlace = "Hotel";
            budget *= 0.80;
        }
    } else if (budget > 1000) {
        destination = "Europe";
        vacationPlace = "Hotel";
        budget *= 0.90;
    }

    cout.setf(ios::fixed);
    cout.precision(2);


    cout << "Somewhere in " << destination << endl;
    cout << vacationPlace << " - " << budget << endl;

    return 0;
}
