#include <iostream>
#include <string>

using namespace std;


int main() {

    for (int hour = 0; hour <= 23; hour++) {
        for (int minutes = 0; minutes <= 59; minutes++) {
            cout << hour << ":" << minutes << endl;
        }
    }

    return 0;
}