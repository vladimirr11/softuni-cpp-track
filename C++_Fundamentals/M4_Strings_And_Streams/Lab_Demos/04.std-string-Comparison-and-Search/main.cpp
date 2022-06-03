#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "–aA:)", s2 = "asd=@";

    if (s1 < s2) {
        cout << s1 << " is before " << s2 << endl;
    } else {
        cout << s1 << " is after " << s2 << endl;
    }

    cout << "nar" << " is at index " << s2.find("nar") << " in " << s2 << endl;
    cout << s1.compare(s2) << endl;;

    return 0;
}
