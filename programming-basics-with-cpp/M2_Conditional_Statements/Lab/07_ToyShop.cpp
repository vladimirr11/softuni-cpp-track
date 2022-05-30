#include <iostream>

using namespace std;

int main() {
    double priceHoliday;
    int puzzles, dolls, bears, minions, trucks;

    cin >> priceHoliday >> puzzles >> dolls >> bears >> minions >> trucks;

    double PRICEPUZZLES = 2.6;
    double PRICEDOLLS = 3.0;
    double PRICEBEARS = 4.1;
    double PRICEMINIONS = 8.2;
    double PRICETRUCKS = 2;

    int sumToys = puzzles + dolls + bears + minions + trucks;

    cout.setf(ios::fixed);
    cout.precision(2);

    if (sumToys >= 50) {
        double afterDiscount = ((puzzles * PRICEPUZZLES) + (dolls * PRICEDOLLS) + 
        (bears * PRICEBEARS) + (minions * PRICEMINIONS) + (trucks * PRICETRUCKS)) * 0.75;

        double afterRent = afterDiscount - (afterDiscount * 0.1);

        if (afterRent >= priceHoliday) {
            cout << "Yes! " << afterRent - priceHoliday << " lv left." << endl;
        } else {
            cout << "Not enough money! " << priceHoliday - afterRent << " lv needed." << endl;
        }

    } else {
        double rent = (puzzles * PRICEPUZZLES) + (dolls * PRICEDOLLS) + 
        (bears * PRICEBEARS) + (minions * PRICEMINIONS) + (trucks * PRICETRUCKS);

        double afterRent = rent - (rent * 0.1);

        if (afterRent >= priceHoliday) {
            cout << "Yes! " << afterRent - priceHoliday << " lv left." << endl;
        } else {
            cout << "Not enough money! " << priceHoliday - afterRent << " lv needed." << endl;
        }

    }
    return 0;
}
