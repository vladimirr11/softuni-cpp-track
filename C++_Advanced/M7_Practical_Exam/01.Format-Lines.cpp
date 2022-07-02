#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> readInputText() {
    std::vector<std::string> inputWords;

    while (true) {
        std::string line;
        getline(std::cin, line);
        if (line == "###") {
            break;
        }

        std::istringstream istr(line);

        std::string currWord;
        while (istr >> currWord) {
            inputWords.push_back(currWord);
        }
    }

    return inputWords;
}

void formatText(const std::vector<std::string>& inputWords, int lineWidth) {
    std::string outputLine;
    int lastLineStartIdx = 0;
    for (size_t i = 0; i < inputWords.size() - 1; i++) {
        if (outputLine.size() < lineWidth) {
            outputLine += inputWords[i];
            outputLine += " ";
            if (outputLine.size() + inputWords[i + 1].size() > lineWidth) {
                std::cout << outputLine << std::endl;
                outputLine.clear();
                outputLine = "";
            }
            lastLineStartIdx = i;
        }
    }

    for (int i = lastLineStartIdx + 1; i < inputWords.size(); i++) {
        outputLine += inputWords[i];
        outputLine += " ";
    }

    std::cout << outputLine << std::endl;
}

int main() {
    std::vector<std::string> inputWords = readInputText();

    int lineWidth = 0;
    std::cin >> lineWidth;

    formatText(inputWords, lineWidth);

    return 0;
}
