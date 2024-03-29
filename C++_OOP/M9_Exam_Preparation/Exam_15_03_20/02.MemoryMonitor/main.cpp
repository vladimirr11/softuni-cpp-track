#include <iostream>
#include <string>

#include "CommandExecutor.h"

#include "CommandExecutor.h"
#include "MemoryMonitor.h"

int main() {
    int commands = 0;
    std::string input;

    std::cin >> commands;
    std::cin.ignore();

    CommandExecutor commandExecutor;

    for (int i = 0; i < commands; ++i) {
        getline(std::cin, input);

        commandExecutor.extractCommand(input);
    }

    return 0;
}
