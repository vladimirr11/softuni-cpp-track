#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int minNumber;
    cin >> minNumber;
    
    n--;
    while (n-- > 0) {
        int currentNumber;
        cin >> currentNumber;
        if (minNumber > currentNumber) {
            minNumber = currentNumber;
        }
    }

    cout << minNumber << endl;

    return 0;
}
