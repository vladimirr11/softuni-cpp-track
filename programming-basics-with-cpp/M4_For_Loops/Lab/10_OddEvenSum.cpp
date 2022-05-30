#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int evenNumsSum = 0, oddNumsSum = 0;

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        if (i % 2 == 0) {
            evenNumsSum += number;
        } else {
            oddNumsSum += number;
        }
    }

    if (evenNumsSum == oddNumsSum) {
        cout << "Yes" << endl << "Sum = " << oddNumsSum << endl;
    } else {
        cout << "No" << endl << "Diff = " << std::abs(oddNumsSum - evenNumsSum) << endl;
    }
    
    return 0;
}
