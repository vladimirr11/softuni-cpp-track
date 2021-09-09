#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main() {

    int goalGabi = 10000, totalSteps = 0;

    while (totalSteps < goalGabi) {
        // int madeSteps;
        string steps;
        getline(cin, steps);

        if (steps == "Going home") {
            int lastSteps;
            cin >> lastSteps;
            totalSteps += lastSteps;
            if (totalSteps >= goalGabi) {
                cout << "Goal reached! Good job!" << endl;
                break;
            } else {
                cout << goalGabi - totalSteps << " more steps to reach goal." << endl;
                break;
            }
        } else {
            totalSteps += stoi(steps);
            if (totalSteps >= goalGabi) {
                cout << "Goal reached! Good job!" << endl;
                break;
            }
        }
    }

    return 0;
}