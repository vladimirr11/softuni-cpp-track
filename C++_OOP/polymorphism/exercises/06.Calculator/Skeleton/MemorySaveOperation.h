#ifndef MEMORYSAVEOPERATION_H
#define MEMORYSAVEOPERATION_H

#include "Operation.h"

#include <stack>

class MemorySaveOperation : public Operation {
public:
    virtual void addOperand(int operand) final {
        _memoryOperands.push(operand);
    }

    virtual int getResult() final {
        const int lastOperand = _memoryOperands.top();
        _memoryOperands.pop();
        return lastOperand;
    }

    virtual bool isCompleted() final {
        return false;
    }

private:
    std::stack<int> _memoryOperands;
};

#endif // !MEMORYSAVEOPERATION_H
