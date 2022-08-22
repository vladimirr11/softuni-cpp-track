#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include "AdvancedCommandInterface.h"
#include "CommandInterface.h"

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text) {
    std::shared_ptr<CommandInterface> interface = std::make_shared<AdvancedCommandInterface>(text);

    interface->init();
    
    return interface;
}

#endif // !INITIALIZATION_H
