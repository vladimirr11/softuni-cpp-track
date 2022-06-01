#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int widthCake, heightCake;
    cin >> widthCake >> heightCake;

    int areaCake = widthCake * heightCake;

    while (areaCake > 0) {
        string numCakes;
        cin >> numCakes;

        if (numCakes == "STOP") {
            cout << areaCake << " pieces are left." << endl;
            break;
        }   

        areaCake -= stoi(numCakes);
    }

    if (areaCake <= 0) {
        cout << "No more cake left! You need " << std::abs(areaCake) << " pieces more." << endl;
    }   

    return 0;
}
