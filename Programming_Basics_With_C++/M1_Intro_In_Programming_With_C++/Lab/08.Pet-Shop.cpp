#include <iostream>

using namespace std;

int main() {
    int num_dogs, num_others;
    cin >> num_dogs >> num_others;

    cout.setf(ios::fixed);
    cout.precision(2);

    double total_price = num_dogs * 2.5 + num_others * 4;

    cout << total_price << " lv.";

    return 0;
}
