#include <iostream>

using namespace std;


int main() {

    int p1 = 0, p2 = 0, p3 = 0;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int number;
        cin >> number;
        if (number % 2 == 0) {
            p1 += 1;
        }
        if (number % 3 == 0) {
            p2 += 1;
        }
        if (number % 4 == 0) {
            p3 += 1;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << ((p1 * 1.0) / n) * 100 << "%" << endl;
    cout << ((p2 * 1.0) / n) * 100 << "%" << endl;
    cout << ((p3 * 1.0) / n) * 100 << "%" << endl;

    return 0;
}