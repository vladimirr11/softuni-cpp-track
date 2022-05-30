#include <iostream>

using namespace std;

int main() {
    int number;
    cin >> number;

    double bonusScore;

    if (number % 2 == 0){
        bonusScore += 1;
    }

    if (number % 5 == 0 && number % 10 != 0) {
        bonusScore += 2;
    }

    if (number <= 100) {
        bonusScore += 5;
        cout << bonusScore << endl << number + bonusScore << endl;
    } else if (number > 100 && number <= 1000) {
        bonusScore += number * 0.2;
        cout << bonusScore << endl << number + bonusScore << endl;
    } else {
        bonusScore += number * 0.1;
        cout << bonusScore << endl << number + bonusScore << endl;
    }

    return 0;
}
