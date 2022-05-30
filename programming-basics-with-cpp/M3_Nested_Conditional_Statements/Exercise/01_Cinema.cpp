#include <iostream>
#include <string>

using namespace std;

int main() {
    string typeMovie;
    int numRows, numCols;

    cin >> typeMovie >> numRows >> numCols;

    double price;

    if (typeMovie == "Premiere") {
        price = 12.00;
    }else if (typeMovie == "Normal") {
        price = 7.50;
    } else if (typeMovie == "Discount") {
        price = 5.00;
    }

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << price * numRows * numCols << " leva" << endl;

    return 0;
}
