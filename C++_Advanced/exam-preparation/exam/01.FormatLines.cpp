#include <iostream>
#include <string>
#include <sstream>

std::string readInputText() {
    std::string inputText;

    while (true) {
        std::string line;
        getline(std::cin, line);

        if (line == "###") {
            break;
        }

        std::istringstream istr(line);

        std::string currWord;
        while (istr >> currWord) {
            inputText.append(currWord).append(" ");
        }
    }

    return inputText;
}

void prepareAndPrintSolution(std::string& inputText, int numWordsPerLine) {

    while (!inputText.empty()) {
        std::size_t found = inputText.find_last_of(" ", numWordsPerLine);
        if (found != std::string::npos) {
            std::string newLine = inputText.substr(0, found);
            std::cout << newLine << std::endl;
            inputText.erase(0, newLine.size() + 1);
        }
    }

}

int main() {
    std::string inputText = readInputText();

    int numWordsPerLine = 0;
    std::cin >> numWordsPerLine;

    prepareAndPrintSolution(inputText, numWordsPerLine);

    return 0;
}
