#include <iostream>
#include <vector>
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

void executeCopyPasteOnText(std::string& text, std::vector<std::string>& copyPasteVec) {
    std::stack<std::string> copiedTextStack {};

    for (auto operation : copyPasteVec) {
        std::istringstream istr(operation);

        std::string oper;
        int copyFrom = 0;
        int copyTo = 0;
        int pastePos = 0;

        istr >> oper;
        if (oper == "copy") {
            istr >> copyFrom >> copyTo;

            size_t foundStartIndx = text.find_last_of(" ", copyFrom);

            int startIdx = 0;
            if (foundStartIndx != std::string::npos) {
                startIdx = foundStartIndx + 1;
            } 

            size_t foundEndIdx = text.find_first_of(" ", copyTo);

            int endIdx = 0;
            if (foundEndIdx != std::string::npos) {
                endIdx = foundEndIdx;
            } else {
                endIdx = text.size();
            }

            copiedTextStack.push(text.substr(startIdx, endIdx - startIdx));

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
        }
    }
}

int main() {
    std::string text = readInputText();
    std::vector<std::string> copyPasteVec = readCopyPasteOperations();

    executeCopyPasteOnText(text, copyPasteVec);

    std::cout << text << std::endl;

    return 0;
}
