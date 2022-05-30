#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    for (int i = m; i >= n; i--) {
        if (i % 2 == 0 && i % 3 == 0) {
            if (i == s) {
                break;
            } else {
                cout << i << " ";
            }
        }
    }

    return 0;
}
