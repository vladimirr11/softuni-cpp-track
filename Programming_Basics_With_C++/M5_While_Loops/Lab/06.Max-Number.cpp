#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int maxNumber;
    cin >> maxNumber;

    while (--n > 0) {
        int currentNumber;
        cin >> currentNumber;
        if (maxNumber < currentNumber) {
            maxNumber = currentNumber;
        }
    }

    cout << maxNumber << endl;

    return 0;
}
