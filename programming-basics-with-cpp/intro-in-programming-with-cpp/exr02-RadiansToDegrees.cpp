#include <iostream>
#include <math.h>

using namespace std;


int main() {

    double rad;
    cin >> rad;

    double degrees = rad * 180 / 3.14;

    cout << round(degrees) << endl;
    
    return 0;
}