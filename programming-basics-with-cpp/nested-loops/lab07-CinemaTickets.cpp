#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main() {

    cin.sync_with_stdio(true);
    cout.sync_with_stdio(true);

    int total = 0, student = 0, standard = 0, kid = 0;

    cout.setf(ios::fixed);
    cout.precision(2);

    while (true) {
        string movie;
        getline(cin, movie);

        if (movie == "Finish") {
            break;
        }

        string seatsAsString;
        getline(cin, seatsAsString);
        int seats = stoi(seatsAsString);
        int movieSeats = stoi(seatsAsString);

        int counterCurrentMovie = 0;

        while (seats > 0) {
            seats--;

            string ticket;
            getline(cin, ticket);

            if (ticket == "End") {
                break;
            } else if (ticket == "student") {
                counterCurrentMovie++;
                total++;
                student++;
            } else if (ticket == "standard") {
                counterCurrentMovie++;
                total++;
                standard++;
            } else if (ticket == "kid") {
                counterCurrentMovie++;
                total++;
                kid++;
            }

        }

        cout << movie << " - " << ((counterCurrentMovie * 1.0) / movieSeats) * 100 << "% full." << endl;
    }

    cout << "Total tickets: " << total << endl;
    cout << ((student * 1.0) / total) * 100 << "% student tickets." << endl;
    cout << ((standard * 1.0) / total) * 100 << "% standard tickets." << endl;
    cout << ((kid * 1.0) / total) * 100 << "% kids tickets." << endl;

    return 0;
}