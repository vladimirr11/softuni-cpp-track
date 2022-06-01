#include <iostream>
#include <string>

using namespace std;

int main() {
    string flowers;
    int numFlowers, budget;

    cin >> flowers >> numFlowers >> budget;

    double rosesPrice = 5;
    double dahliasPrice = 3.8;
    double tulipsPrice = 2.8;
    double narcissusPrice = 3;
    double gladiolusPrice = 2.5;

    if (flowers == "Roses" && numFlowers > 80) {
        rosesPrice *= 0.9;
    } else if (flowers == "Dahlias" && numFlowers > 90) {
        dahliasPrice *= 0.85;
    } else if (flowers == "Tulips" && numFlowers > 80) {
        tulipsPrice *= 0.85;
    } else if (flowers == "Narcissus" && numFlowers < 120) {
        narcissusPrice *= 1.15;
    } else if (flowers == "Gladiolus" && numFlowers < 80) {
        gladiolusPrice *= 1.20;
    }

    double totalSum;
    
    if (flowers == "Roses") {
        totalSum = rosesPrice * numFlowers;
    } else if (flowers == "Dahlias") {
        totalSum = dahliasPrice * numFlowers;
    } else if (flowers == "Tulips") {
        totalSum = tulipsPrice * numFlowers;
    } else if (flowers == "Narcissus") {
        totalSum = narcissusPrice * numFlowers;
    } else if (flowers == "Gladiolus") {
        totalSum = gladiolusPrice * numFlowers;
    }

    cout.setf(ios::fixed);
    cout.precision(2);

    if (totalSum > budget) {
        cout << "Not enough money, you need " << totalSum - budget << " leva more." << endl;
    } else {
        cout << "Hey, you have a great garden with " << numFlowers << " " << flowers
        << " and " << budget - totalSum << " leva left." << endl;
    }
    return 0;
}
