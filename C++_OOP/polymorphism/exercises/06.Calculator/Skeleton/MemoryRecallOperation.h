#ifndef MEMORYRECALLOPERATION_H
#define MEMORYRECALLOPERATION_H

#include "Operation.h"
#include "MemorySaveOperation.h"

#include <memory>

class MemoryRecallOpearation : public Operation {
public:
    MemoryRecallOpearation(std::shared_ptr<MemorySaveOperation>& memSaveOp) :
        _memorySave(memSaveOp) {}

    virtual void addOperand(int /*operand*/) final {
        // without implementation
    }

    virtual int getResult() final {
        return _memorySave->getResult();
    }

    virtual bool isCompleted() final {
        return true;
    }

private:
    std::shared_ptr<MemorySaveOperation> _memorySave;
};

#endif // !MEMORYRECALLOPERATION_H
