#ifndef EXTENDEDINPUTINTERPRETER_H
#define EXTENDEDINPUTINTERPRETER_H

#include <memory>
#include <sstream>

#include "InputInterpreter.h"
#include "DivisionOperation.h"
#include "MemoryRecallOperation.h"
#include "MemorySaveOperation.h"
#include "Operation.h"

class ExtendedInputInterpreter : public InputInterpreter {
public:
    ExtendedInputInterpreter(CalculationEngine& engine) : InputInterpreter(engine) {}

    virtual ~ExtendedInputInterpreter() = default;

    std::shared_ptr<Operation> getOperation(std::string operation) final {
        if (operation == "/") {
            return std::make_shared<DivisionOperation>();

        } else if (operation == "ms") {
            if (!_memorySaveOperation) {
                _memorySaveOperation = std::make_shared<MemorySaveOperation>();
            }
            return _memorySaveOperation;

        }  else if (operation == "mr") {
            return std::make_shared<MemoryRecallOpearation>(_memorySaveOperation);
        }

        return InputInterpreter::getOperation(operation);
    }

private:
    std::shared_ptr<MemorySaveOperation> _memorySaveOperation;
};

#endif // !EXTENDEDINPUTINTERPRETER_H
