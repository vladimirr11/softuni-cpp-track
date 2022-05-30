#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n;
    cin >> n;

    int counter = 0;

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            for (int z = 0; z <= n; z++) {
                if (x + y + z == n) {
                    counter++;
                }
            }
        }
    }

    cout << counter << endl;
    
    return 0;
}
