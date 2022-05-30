#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int adults = 0, kids = 0;

    while (true) {
        string input;
        cin >> input;

        if (input == "Christmas") {
            break;
        }

        int age = stoi(input);

        if (age <= 16) {
            kids++;
        } else {
            adults++;
        }

    }

    cout << "Number of adults: " << adults << endl;
    cout << "Number of kids: " << kids << endl;
    cout << "Money for toys: " << kids * 5 << endl;
    cout << "Money for sweaters: " << adults * 15 << endl;

    return 0;
}
