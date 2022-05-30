#include <iostream>
#include <string>

using namespace std;

int main() {
    int numAssesments, counter = 0, sumAssessment = 0, counterBadAssesment = 0;
    cin >> numAssesments;

    cin.ignore();

    string lastProblem;

    cout.setf(ios::fixed);
    cout.precision(2);

    while (true) {
        string task;
        getline(cin, task);

        if (task == "Enough") {
            cout << "Average score: " << (sumAssessment * 1.0) / counter << endl;
            cout << "Number of problems: " << counter << endl;
    	    cout << "Last problem: " << lastProblem << endl;
            break;
        }

        int assesment;
        cin >> assesment;

        if (assesment <= 4) {
            counterBadAssesment += 1;
        }

        cin.ignore();

        sumAssessment += assesment;
        counter++;

        if (counterBadAssesment == numAssesments) {
            cout << "You need a break, " << counterBadAssesment << " poor grades." << endl;
            break;
        }

        lastProblem = task;

    }

    return 0;
}
