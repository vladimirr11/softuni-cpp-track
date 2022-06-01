#include <iostream>
#include <string>

using namespace std;

int main(){
    int firstNum, secondNum;
    char operatorr;
    cin >> firstNum >> secondNum >> operatorr;

    int output;
    double outputDev;
    string evenOdd;

    cout.setf(ios::fixed);
    cout.precision(2);

    if (operatorr == '+') {
        output = firstNum + secondNum;
        if (output % 2 == 0) {
            evenOdd = "even";
        } else {
            evenOdd = "odd";
        }
        cout << firstNum << " "<< operatorr << " " << secondNum << " = " << output << 
        " - " << evenOdd << endl;
    } else if (operatorr == '-') {
        output = firstNum - secondNum;
        if (output % 2 == 0) {
            evenOdd = "even";
        } else {
            evenOdd = "odd";
        }
        cout << firstNum << " "<< operatorr << " " << secondNum << " = " << output << 
        " - " << evenOdd << endl;
    } else if (operatorr == '*') {
        output = firstNum * secondNum;
        if (output % 2 == 0) {
            evenOdd = "even";
        } else {
            evenOdd = "odd";
        }
        cout << firstNum << " "<< operatorr << " " << secondNum << " = " << output << 
        " - " << evenOdd << endl;
    } else if (operatorr == '%') {
        output = firstNum % secondNum;

        cout << firstNum << " " << operatorr << " " << secondNum << " = " << output << endl;
    } else {
        if (secondNum == 0) {
            cout << "Cannot divide " << firstNum << " by zero";
        } else {
            outputDev = firstNum * 1.0 / secondNum;

            cout << firstNum << " " << operatorr << " " << secondNum << " = " << outputDev << endl;
        }
    }

    return 0;
}
