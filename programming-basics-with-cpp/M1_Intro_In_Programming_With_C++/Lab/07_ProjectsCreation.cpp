#include <iostream>

using namespace std;

int main() {
    string name;
    cin >> name;

    int num_projects;
    cin >> num_projects;

    int time_needed = num_projects * 3;

    cout << "The architect " << name << " will need "
    << time_needed << " hours to complete " << num_projects << " project/s.";

    return 0;
}
