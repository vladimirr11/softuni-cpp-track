#include <iostream>
#include <string>

using namespace std;

int main() {
    int degrees;
    string dayTime;

    cin >> degrees >> dayTime;

    string outfit, shoes;

    if (dayTime == "Morning" && (10 <= degrees && degrees <= 18)) {
        outfit = "Sweatshirt";
        shoes = "Sneakers";
    } else if (dayTime == "Morning" && (18 < degrees && degrees <= 24)) {
        outfit = "Shirt";
        shoes = "Moccasins";
    } else if (dayTime == "Morning" && (degrees >= 25)) {
        outfit = "T-Shirt";
        shoes = "Sandals";
    } else if (dayTime == "Afternoon" && (10 <= degrees && degrees <= 18)) {
        outfit = "Shirt";
        shoes = "Moccasins";
    } else if (dayTime == "Afternoon" && (18 < degrees && degrees <= 24)) {
        outfit = "T-Shirt";
        shoes = "Sandals";
    } else if (dayTime == "Afternoon" && (degrees >= 25)) {
        outfit = "Swim Suit";
        shoes = "Barefoot";
    } else if (dayTime == "Evening" && (10 <= degrees && degrees <= 18)) {
        outfit = "Shirt";
        shoes = "Moccasins";
    } else if (dayTime == "Evening" && (18 < degrees && degrees <= 24)) {
        outfit = "Shirt";
        shoes = "Moccasins";
    } else if (dayTime == "Evening" && (degrees >= 25)) {
        outfit = "Shirt";
        shoes = "Moccasins";
    }

    cout << "It's " << degrees << " degrees, get your " << outfit << " and " << shoes << "." << endl;

    return 0;
}
