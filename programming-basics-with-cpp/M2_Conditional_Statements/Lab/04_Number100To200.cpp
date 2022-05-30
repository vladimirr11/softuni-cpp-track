#include <iostream>
#include <string>

using namespace std;

int main() {
    int number;
    cin >> number;

    string output;

    if (number < 100){
        output = "Less than 100";
    } else if (number >= 100 && number <= 200) {
        output = "Between 100 and 200";
    } else {
        output = "Greater than 200";
    }

    cout << output << endl;
    
    return 0;
}
