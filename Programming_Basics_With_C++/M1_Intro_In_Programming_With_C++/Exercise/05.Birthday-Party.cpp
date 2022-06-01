#include <iostream>

using namespace std;

int main() {
    int hallRent;
    cin >> hallRent;

    double priceCake = hallRent * 0.2;
    double priceBedverage = priceCake - (priceCake * 0.45);
    double animator = hallRent / 3;

    double budget = priceCake + priceBedverage + animator;

    cout << hallRent + budget << endl;

    return 0;
}
