#include <iostream>

using namespace std;

int main() {
    double square_meters;
    cin >> square_meters;

    double final_price = square_meters * 7.61;
    double discount = final_price * 0.18;

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "The final price is: " << final_price - discount << " lv." << endl;
    cout << "The discount is: " << discount << " lv.";

    return 0;
}
