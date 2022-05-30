#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double record, distance, secondsToMeter;
    cin >> record >> distance >> secondsToMeter;

    double timeContestant = secondsToMeter * distance;

    int timesTimeToAdd;

    if (distance >= 15) {
        timesTimeToAdd = (int) distance / 15;
    	timeContestant += (timesTimeToAdd * 12.5);
    }   

    cout.setf(ios::fixed);
    cout.precision(2);

    if (timeContestant >= record) {
        cout << "No, he failed! He was " << timeContestant - record << " seconds slower." << endl;
    } else {
        cout << "Yes, he succeeded! The new world record is " << timeContestant 
        << " seconds." << endl;
    }

    return 0;
}
