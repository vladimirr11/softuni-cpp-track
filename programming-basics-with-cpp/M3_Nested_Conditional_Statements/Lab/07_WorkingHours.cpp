#include <iostream>
#include <string>

using namespace std;

int main() {
    int hour;
    string dayOfWeek;

    cin >> hour >> dayOfWeek;

    string output;

    if ((hour >= 10 && hour < 18) && (dayOfWeek == "Monday" || dayOfWeek == "Tuesday" || dayOfWeek == "Wednesday"
    || dayOfWeek == "Thursday" || dayOfWeek == "Friday" || dayOfWeek == "Saturday")) {
        output = "open";
    } else {
        output = "closed";
    }
    
    cout << output << endl;

    return 0;
}
