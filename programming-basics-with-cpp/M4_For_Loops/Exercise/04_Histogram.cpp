#include <iostream>

using namespace std;

int main() {
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int number;
        cin >> number;
        if (number < 200) {
            p1 += 1;
        } else if (number >= 200 && number < 400) {
            p2 += 1;
        } else if (number >=400 && number < 600) {
            p3 += 1;
        } else if (number >= 600 && number < 800) {
            p4 += 1;
        } else if (number >= 800) {
            p5 += 1;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << ((p1 * 1.0) / n) * 100 << "%" << endl;
    cout << ((p2 * 1.0) / n) * 100 << "%" << endl;
    cout << ((p3 * 1.0) / n) * 100 << "%" << endl;
    cout << ((p4 * 1.0) / n) * 100 << "%" << endl;
    cout << ((p5 * 1.0) / n) * 100 << "%" << endl;

    return 0;
}
