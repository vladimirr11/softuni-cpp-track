#ifndef ADVANCEDCOMMANDTRANSFORM_H
#define ADVANCEDCOMMANDTRANSFORM_H

#include <memory>

#include "CommandInterface.h"
#include "CutTransform.h"
#include "PasteTransform.h"

class AdvancedCommandInterface : public CommandInterface {
public:
    AdvancedCommandInterface(std::string& text) : CommandInterface(text) {}

    virtual std::vector<Command> initCommands() override {
        std::vector<Command> commands = CommandInterface::initCommands();

        commands.push_back(Command("cut", std::make_shared<CutTransform>()));
        commands.push_back(Command("paste", std::make_shared<PasteTransform>()));

        return commands;
    }
};

#endif // !ADVANCEDCOMMANDTRANSFORM_H
