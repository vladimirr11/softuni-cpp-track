#include <iostream>
#include <cstdlib>
#include <array>
#include <ctime>

int getRandomNumber(int lowRange, int highRange) {
    return lowRange + (rand() % (highRange - lowRange + 1));
}

char generateRandomDigitCharacter() {
    const int lowRange = 0;
    const int highRange = 9;

    const int randomNumber = getRandomNumber(lowRange, highRange);

    return char(randomNumber + '0');
}

char generateRandomSymbol() {
    std::array<char, 5> symbols = {',', '!', '?', '@', ';'};
    const int index = getRandomNumber(0, symbols.size() - 1);

    const char chosenSymbol = symbols[index];

    return chosenSymbol;
}

int main() {
    srand(time(nullptr));

    std::array<char, 1000> array {};
    int currentCharIdx = 0;

    const int digitsToGenerate = getRandomNumber(2, 9);

    for (int i = 0; i < digitsToGenerate; i++) {
        array[currentCharIdx] = generateRandomDigitCharacter();
        currentCharIdx++;

        const int randomSymbolsToGenerate = getRandomNumber(0, 5);
        
        for (int j = 0; j < randomSymbolsToGenerate; j++) {
            array[currentCharIdx] = generateRandomSymbol();
            currentCharIdx++;
        }   
    }

    for (int i = 0; i < currentCharIdx; i++) {
        std::cout << array[i];
    }
    std::cout << '.' << std::endl;

    return 0;
}
