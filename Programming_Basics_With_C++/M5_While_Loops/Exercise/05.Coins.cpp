#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    double oldChange;
    int counter = 0;
    cin >> oldChange;

    int change = oldChange * 100;

    while (change != 0) {
        if (change >= 200) {
            counter += change / 200;
            change %= 200;
        }
        if (change >= 100) {
            counter += change / 100;
            change %= 100;
        }
        if (change >= 50) {
            counter += change / 50;
            change %= 50;
        }
        if (change >= 20) {
            counter += change / 20;
            change %= 20;
        }
        if (change >= 10) {
            counter += change / 10;
            change %= 10;
        }
        if (change >= 5) {
            counter += change / 5;
            change %= 5;
        }
        if (change >= 2) {
            counter += change / 2;
            change %= 2;
        }
        if (change == 1) {
            counter += change / 1;
            change %= 1;
        }

    }

    cout << counter << endl;

    return 0;
}
