#include <iostream>
#include <string>

using namespace std;


int main() {

    string input;
    cin >> input;

    int sumNums = 0;

    while (input != "Stop") {
    sumNums += stoi(input);
    cin >> input;
    }

    cout << sumNums << endl;

    return 0;
}