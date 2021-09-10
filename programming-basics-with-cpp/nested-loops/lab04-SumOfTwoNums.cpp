#include <iostream>
#include <string>

using namespace std;


int main() {

    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int begin, end, target;
    cin >> begin >> end >> target;

    bool targetReached = false;
    int counter = 0;

    for (int left = begin; left <= end; left++) {
        for (int right = begin; right <= end; right++) {
            counter++;
            if (left + right == target) {
                cout << "Combination N:" << counter << 
                " (" << left << " + " << right << " = " << target << ")" << endl;
                targetReached = true;
                break;
            }
        }

        if (targetReached) {
            break;
        }

    }

    if (!targetReached) {
        cout << counter << " combinations - neither equals " << target << endl;
    }

    return 0;
}