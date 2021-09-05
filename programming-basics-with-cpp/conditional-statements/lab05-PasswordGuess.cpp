#include <iostream>
#include <string>

using namespace std;


int main() {

    string pass;
    cin >> pass;

    string passToCheck = "s3cr3t!P@ssw0rd";

    if (pass == passToCheck){
        cout << "Welcome" << endl;
    } else {
        cout << "Wrong password!" << endl;
    }

    return 0;
}