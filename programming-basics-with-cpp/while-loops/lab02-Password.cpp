#include <iostream>
#include <string>

using namespace std;


int main() {

    string userName, pass;
    cin >> userName >> pass;

    string input;
    cin >> input;

    while (pass != input) {
        cin >> input;
    }
    
    cout << "Welcome " << userName << "!" << endl;
    
    return 0;
}