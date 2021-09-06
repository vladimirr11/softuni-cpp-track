#include <iostream>
#include <string>

using namespace std;


int main() {

    string dayOfWeek;
    cin >> dayOfWeek;

    int output;

    if (dayOfWeek == "Monday" || dayOfWeek == "Tuesday" || dayOfWeek == "Friday") {
        output = 12;
    } else if (dayOfWeek == "Wednesday" || dayOfWeek == "Thursday") {
        output = 14;
    } else {
        output = 16;
    }
    
    cout << output << endl;

    return 0;
}