#include <iostream>
#include <string>

using namespace std;


int main(){

    string figure;
    cin >> figure;

    double output;
    double pi = 3.14159265359;

    if (figure == "square") {
        double side;
        cin >> side;

        output = side * side;

    } else if (figure == "rectangle") {
        double a, b;
        cin >> a >> b;

        output = a * b;

    } else if (figure == "circle") {
        double radius;
        cin >> radius;

        output = radius * radius * pi;
    } else if (figure == "triangle") {
        double a, h;
        cin >> a >> h;

        output = (a * h) / 2;
    }

    cout.setf(ios::fixed);
    cout.precision(3);

    cout << output << endl;

    return 0;
}