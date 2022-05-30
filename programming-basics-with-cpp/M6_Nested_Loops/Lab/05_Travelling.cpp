#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    string destination;
    getline(cin, destination);

    while (destination != "End") {
        string costAsString;
        getline(cin, costAsString);

        int budget = stoi(costAsString);

        while (budget > 0) {
            string savings;
            getline(cin, savings);
            budget -= stoi(savings);
        }

        cout << "Going to " << destination << "!" << endl;
        getline(cin, destination);
    }
    
    return 0;
}
