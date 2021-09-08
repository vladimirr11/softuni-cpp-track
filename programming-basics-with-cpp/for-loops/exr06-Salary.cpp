#include <iostream>
#include <string>

using namespace std;


int main() {

    int n, salary;
    cin >> n >> salary;

    bool flag = false;

    for (int i = 1; i <= n; i++) {
        string webSite;
        cin >> webSite;

        if (webSite == "Facebook") {
            salary -= 150;
            if (salary <= 0) {
                cout << "You have lost your salary." << endl;
                flag = true;
                break;
            }
        }
        else if (webSite == "Instagram") {
            salary -= 100;
            if (salary <= 0) {
                cout << "You have lost your salary." << endl;
                flag = true;
                break;
            }
        }
        else if (webSite == "Reddit") {
            salary -= 50;
            if (salary <= 0) {
                cout << "You have lost your salary." << endl;
                flag = true;
                break;
            }
        }
    }

    if (flag == false) {
        cout << salary << endl;
    }

    return 0;
}