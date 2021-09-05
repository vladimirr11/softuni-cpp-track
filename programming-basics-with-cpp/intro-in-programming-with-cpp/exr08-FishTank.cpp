#include <iostream>

using namespace std;


int main() {

    int lenght, width, height; 
    double percent;

    cin >> lenght >> width >> height >> percent;

    double volume = (lenght * width * height * 0.001) * (1 - (percent / 100));

    cout.setf(ios::fixed);
    cout.precision(2);

    cout << volume << endl;

    return 0;
}