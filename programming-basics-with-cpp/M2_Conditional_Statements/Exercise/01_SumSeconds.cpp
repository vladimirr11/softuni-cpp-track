#include <iostream>

using namespace std;

int main() {
    int first, second, third;
    cin >> first >> second >> third;

    int sumSeconds = first + second + third;
    int seconds = sumSeconds % 60;
    int minutes = sumSeconds / 60;

    if (seconds < 10) {
        cout << minutes << ":0" << seconds << endl;
    } else {
        cout << minutes << ":" << seconds << endl;
    }
    
    return 0;
}
