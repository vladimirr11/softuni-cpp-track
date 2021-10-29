#include "InputParser.h"
#include "CommandExecutor.h"

#include "InputParser.cpp"
#include "Field.cpp"
#include "BomberMan.cpp"
#include "CommandExecutor.cpp"

int main()
{
    InputParser inputParser;
    const FieldData fieldData = inputParser.readField();
    const std::vector<Command> commands = inputParser.readCommands();

    CommandExecutor commandExecutor;
    commandExecutor.executeCommands(fieldData, commands);

    return EXIT_SUCCESS;
}
