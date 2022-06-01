#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int maxNum = INT32_MIN, sumRest = 0;

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        sumRest += number;
        if (number > maxNum) {
            maxNum = number;
        }
    }
    
    int diff = sumRest - maxNum;

    if (diff == maxNum) {
        cout << "Yes" << endl << "Sum = " << maxNum << endl;
    } else {
        cout << "No" << endl << "Diff = " << std::abs(maxNum - diff) << endl;
    }

    return 0;
}
