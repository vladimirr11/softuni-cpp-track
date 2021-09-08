#include <iostream>
#include <string>

using namespace std;


int main() {

    string text;
    getline(cin, text);

    int sumVowels = 0;

    for (int i = 0; i < text.length(); i++) {
        char character = text[i];
        switch (character) {
            case 'a': sumVowels += 1;
                break;
            case 'e': sumVowels += 2;
                break;
            case 'i': sumVowels += 3;
                break;
            case 'o': sumVowels += 4;
                break;
            case 'u': sumVowels += 5;
                break;
            default:
                break;
        }
    }

    cout << sumVowels << endl;

    return 0;
}