#include "MemoryPool.h"

MemoryPool::MemoryPool(const int memoryPoolSize)
    : _memoryBuffer(new int[memoryPoolSize]{}),
      _isMemoryBufferOccupied(new bool[memoryPoolSize]{false}),
      _MEMORY_POOL_SIZE(memoryPoolSize) {}

MemoryPool::~MemoryPool() {
    if (_memoryBuffer) {
        delete[] _memoryBuffer;
        delete[] _isMemoryBufferOccupied;
    }
}

ErrorCode MemoryPool::requestMemory(MemoryNode& outNode) {
    if (_MEMORY_POOL_SIZE >= outNode.size) {

        int startIndx = 0;
        int numFreeNodes = 0;
        for (int i = 0; i < _MEMORY_POOL_SIZE; i++) {
            if (numFreeNodes == 1) {
                startIndx = i - 1;
            }

            if (_isMemoryBufferOccupied[i] == false) {
                numFreeNodes++;
            }
        }

        if (numFreeNodes >= outNode.size) {
            int counter = 0;
            for (int i = startIndx; i < outNode.size; i++) {
                if (counter == outNode.size) {
                    break;
                }
                if (_isMemoryBufferOccupied[i] == false) {
                    _isMemoryBufferOccupied[i] = true;
                    counter++;
                }
            }

            outNode.memory = new int[outNode.size]{};
            outNode.bufferStartIndex = startIndx;

            return ErrorCode::REQUEST_SUCCESS;
        }
        else {
            return ErrorCode::REQUEST_FAILURE_NOT_ENOUGH_MEMORY;
        }
    }

    return ErrorCode::REQUEST_FAILURE_BIGGER_THAN_BUFFER;
}

void MemoryPool::releaseMemory(const MemoryNode& outNode) {
    for (int i = outNode.bufferStartIndex; i < outNode.size; i++) {
        _isMemoryBufferOccupied[i] = false;
    }
}

void MemoryPool::zeroMemoryValue(const MemoryNode& node) {
    for (int i = 0; i < node.size; i++) {
        node.memory[i] = 0;
    }
}

void MemoryPool::occupyMemory(const MemoryNode& node) {
    for (int i = node.bufferStartIndex; i < node.size; i++) {
        _memoryBuffer[i] = node.memory[i];
    }
}
