#include <iostream>
#include <string>

using namespace std;


int main() {

    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << i << " * " << j << " = " << i * j << endl;
        }
    }

    return 0;
}