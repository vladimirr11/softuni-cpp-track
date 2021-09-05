#include <iostream>

using namespace std;


int main() {

    int num_pages, pages_per_hour, num_days;
    cin >> num_pages >> pages_per_hour >> num_days;

    int hours_per_day = ((num_pages * 1.00) / pages_per_hour) / num_days;

    cout << hours_per_day << endl;

    return 0;
}