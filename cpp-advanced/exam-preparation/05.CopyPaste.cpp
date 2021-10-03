#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <stack>

std::string readInputText() {
    std::string text;
    getline(std::cin, text);

    return text;
}

std::vector<std::string> readCopyPasteOperations() {
    std::vector<std::string> copyPasteVec {};

    while (true) {
        std::string line;
        getline(std::cin, line);
        if (line == "end") {
            break;
        }

        copyPasteVec.push_back(line);
    }

    return copyPasteVec;
}

void prepareAndPrintSolution(std::string& text, std::vector<std::string>& copyPasteVec) {

    std::stack<std::string> copiedTextStack = {};

    for (auto operation : copyPasteVec) {
        std::istringstream istr(operation);

        std::string oper;

        int copyStart = 0;
        int copyEnd = 0;

        int pastePos = 0;

        istr >> oper;
        if (oper == "copy") {
            istr >> copyStart >> copyEnd;

            size_t foundStartIndx = text.find_last_of(" ", copyStart);

            int startIdx = 0;
            if (foundStartIndx != std::string::npos) {
                startIdx = foundStartIndx + 1;
            } else {
                startIdx = 0;
            }

            size_t foundEndIdx = text.find_first_of(" ", copyEnd + 1);

            int endIdx = 0;
            if (foundEndIdx != std::string::npos) {
                endIdx = foundEndIdx;
            } else {
                endIdx = text.size() - 1;
            }

            // std::cout << text.substr(startIdx, endIdx) << std::endl;
            copiedTextStack.push(text.substr(startIdx, endIdx));

        } else if (oper == "paste") {
            istr >> pastePos;

            if (copiedTextStack.size() == 0) {
                continue;
            }

            std::string textToPaste = copiedTextStack.top();
            copiedTextStack.pop();

            if (isspace(text[pastePos])) {
                text.insert(pastePos + 1, textToPaste);
                text.insert(pastePos + 1 + textToPaste.size(), " ");
            } else {
                text.insert(pastePos, textToPaste);
            }

            // std::cout << text << std::endl;
        }
    }

    // std::size_t doubleSpace = text.find("  ");
    // while (doubleSpace != std::string::npos) {
    //     text.erase(doubleSpace, 1);
    //     doubleSpace = text.find("  ");
    // }

    std::cout << text << std::endl;
}

int main() {
    std::string text = readInputText();
    std::vector<std::string> copyPasteVec = readCopyPasteOperations();

    prepareAndPrintSolution(text, copyPasteVec);

    return 0;
}
