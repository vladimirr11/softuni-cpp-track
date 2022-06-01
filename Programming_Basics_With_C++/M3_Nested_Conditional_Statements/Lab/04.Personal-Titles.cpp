#include <iostream>
#include <string>

using namespace std;

int main() {
    double age;
    char gender;
    cin >> age >> gender;
    
    string output;

    if (age < 16 && gender == 'f') {
        output = "Miss";
    } else if (age >= 16 && gender == 'f') {
        output = "Ms.";
    } else if (age < 16 && gender == 'm') {
        output = "Master";
    } else if (age >= 16 && gender == 'm') {
        output = "Mr.";
    } 
    
    cout << output << endl;
    
    return 0;
}
