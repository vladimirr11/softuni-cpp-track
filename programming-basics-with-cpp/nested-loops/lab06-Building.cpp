#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main() {

    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int floors, rooms;
    cin >> floors >> rooms;

    for (int floor = floors; floor > 0; floor--) {

        char letter;

        if (floor == floors) {
            letter = 'L';
        } else if (floor % 2 == 0) {
            letter = 'O';
        } else if (floor % 2 == 1) {
            letter = 'A';
        }

        for (int room = 0; room < rooms; room++) {
            cout << letter << floor << room << " ";
        }
    	
        cout << endl;
    } 
    
    return 0;
}