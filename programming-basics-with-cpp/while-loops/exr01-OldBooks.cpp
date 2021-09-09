#include <iostream>
#include <string>

using namespace std;


int main() {

    string searchedBook;
    int numBooks;
    getline(cin, searchedBook);

    cin >> numBooks;

    cin.ignore(); 

    int counterBooks = 0;

    while (true) {
        string book;
        getline(cin, book);

        if (book == searchedBook) {
            cout << "You checked " << counterBooks << " books and found it." << endl;
            break;
        }  

        counterBooks++;

        if (counterBooks == numBooks) {
            cout << "The book you search is not here!" << endl << "You checked " << counterBooks << 
            " books.";
            break;
        }
    }
    
    return 0;
}