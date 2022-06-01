#include <iostream>

using namespace std;

int main() {
    int hour, minutes;
    cin >> hour >> minutes;

    int newMinutes = minutes + 15;

    if (newMinutes >= 60) {
        minutes = newMinutes % 60;
        hour += 1;
        if (hour == 24) {
            hour = 0;
        }
        if (minutes < 10) {
            cout << hour << ":0" << minutes << endl;
        } else {
            cout << hour << ":" << minutes << endl;
        }
    } else {
        if (newMinutes < 10) {
            cout << hour << ":0" << newMinutes << endl;
        } else {
            cout << hour << ":" << newMinutes << endl;
        }
    }

    return 0;
}
