#include <iostream>
#include <cmath>

using namespace std;


int main() {

    int n;
    cin >> n;

    double minOddNum = INT8_MAX, maxOddNum = INT8_MIN, minEvenNum = INT8_MAX,
    maxEvenNum = INT8_MIN, sumOdd = 0, sumEven = 0;

    for (int i = 1; i <= n; i++) {
        double number;
        cin >> number;
        if (i % 2 == 0) {
            sumEven += number;
            if (number < minEvenNum) {  
            minEvenNum = number;
            }
            if (number > maxEvenNum) {
            maxEvenNum = number;
            }
        } else {
            sumOdd += number;
            if (number < minOddNum) {  
            minOddNum = number;
            }
            if (number > maxOddNum) {
            maxOddNum = number;
            }
        }
    }

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "OddSum=" << sumOdd << "," << endl;

    if (minOddNum == INT8_MAX) {
        cout << "OddMin=No," << endl;
    } else {
        cout << "OddMin=" << minOddNum << "," << endl;
    }

    if (maxOddNum == INT8_MIN) {
        cout << "OddMax=No," << endl;
    } else {
        cout << "OddMax=" << maxOddNum << "," << endl;
    }

    cout << "EvenSum=" << sumEven << "," << endl;

    if (minEvenNum == INT8_MAX) {
        cout << "EvenMin=No," << endl;
    } else {
        cout << "EvenMin=" << minEvenNum << "," << endl;
    }

    if (maxEvenNum == INT8_MIN) {
        cout << "EvenMax=No" << endl;
    } else {
        cout << "EvenMax=" << maxEvenNum << endl;
    }

    return 0;
}