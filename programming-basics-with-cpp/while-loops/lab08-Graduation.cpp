#include <iostream>
#include <string>

using namespace std;


int main() {

    string student;
    cin >> student;

    int numFails = 0, grade = 1;

    double currentGrade;
    double averageGrade = 0.00;

    bool flag = true;

    while (grade++ <= 12) {
        cin >> currentGrade;
        averageGrade += currentGrade;

        if (currentGrade < 4) {
            grade--;
            numFails += 1;
            if (numFails == 2) {
                flag = false;
                break;
            }
        }
    }

    cout.setf(ios::fixed);
    cout.precision(2);

    if (flag == true) {
        cout << student << " graduated. Average grade: " << averageGrade / 12 << endl;
    } else {
        cout << student << " has been excluded at " << grade << " grade" << endl;
    }

    return 0;
}