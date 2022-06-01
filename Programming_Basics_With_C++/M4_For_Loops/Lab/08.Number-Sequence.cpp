#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int minNum = INT32_MAX, maxNum = INT32_MIN;

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        minNum = min(minNum, number);
        maxNum = max(maxNum, number);
    }

    cout << "Max number: " << maxNum << endl;
    cout << "Min number: " << minNum << endl;

    return 0;
}
