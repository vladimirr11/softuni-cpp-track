#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int leftSum = 0, rightSum = 0;

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        leftSum += number;
    }

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        rightSum += number;
    }

    if (leftSum == rightSum) {
        cout << "Yes, sum = " << leftSum << endl;
    } else {
        cout << "No, diff = " << std::abs(leftSum - rightSum) << endl;
    }

    return 0;
}
