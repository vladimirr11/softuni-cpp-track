#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<int> readPixelsFromInput() {
    int width = 0;
    int height = 0;
    std::cin >> width >>height;

    std::vector<int> pixels(width * height);
    for (auto& pixel : pixels) {
        std::cin >> pixel;
    }

    return pixels;
}

void setBit(int bitValue, int bitIdx, int& value) {
    value |= (bitValue << bitIdx);
}

std::vector<int> constructLettersFromPixels(const std::vector<int>& pixels) {
    const int bitsInByte = 8;
    const int lettersLength = int(pixels.size() / bitsInByte);

    std::vector<int> letters(lettersLength, 0);

    int currBit = 0;
    int currBitIdx = 0;
    for (int i = 0; i < lettersLength; i++) {
        for (int bitId = 0; bitId < bitsInByte; bitId++) {
            currBit = pixels[(i * bitsInByte) + bitId] & 1;
            currBitIdx = bitsInByte - bitId - 1;
            setBit(currBit, currBitIdx, letters[i]);
        }
    }

    return letters;
}

void printSolution(const std::vector<int>& letters) {
    for (const int letter : letters) {
        std::cout << letter;
    }
    std::cout << std::endl;
}

int main() {
    const auto pixels = readPixelsFromInput();
    const auto letters = constructLettersFromPixels(pixels);

    printSolution(letters);

    return 0;
} 
