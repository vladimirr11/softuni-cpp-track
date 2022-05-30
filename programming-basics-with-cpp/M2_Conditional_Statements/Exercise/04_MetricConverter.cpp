#include <iostream>
#include <string>

using namespace std;

int main() {
    double number;
    string input, output;
    cin >> number >> input >> output;

    double result;

    cout.setf(ios::fixed);
    cout.precision(3);

    if (input == "mm" && output == "m") {
        result = number / 1000;
        cout << result << endl;
    } else if (input == "m" && output == "mm") {
        result = number * 1000;
        cout << result << endl;
    } else if (input == "m" && output == "cm") {
        result = number * 100;
        cout << result << endl;
    } else if (input == "cm" && output == "m") {
        result = number / 100;
        cout << result << endl;
    } else if (input == "mm" && output == "cm") {
        result = number / 10;
        cout << result << endl;
    } else if (input == "cm" && output == "mm") {
        result = number * 10;
        cout << result << endl;
    }

    return 0;
}
