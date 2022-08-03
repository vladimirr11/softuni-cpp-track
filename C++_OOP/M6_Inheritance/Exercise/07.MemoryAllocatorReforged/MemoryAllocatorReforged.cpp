#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Defines.h"

enum Action {
    ALLOCATE_SINGLE = 0,
    ALLOCATE_MULTIPLE,
    DEALLOCATE_SINGLE,
    DEALLOCATE_MULTIPLE,
    UNKNOWN_ACTION = 255
};

Action extractAction(const std::string& command) {
    std::istringstream istr(command);
    std::string action, type;
    istr >> action >> type;

    if (action == "Allocate" && type == "Single") {
        return ALLOCATE_SINGLE;
    } else if (action == "Allocate" && type == "Multiple") {
        return ALLOCATE_MULTIPLE;
    } else if (action == "Deallocate" && type == "Single") {
        return DEALLOCATE_SINGLE;
    } else if (action == "Deallocate" && type == "Multiple") {
        return DEALLOCATE_MULTIPLE;
    }

    return UNKNOWN_ACTION;
}

ErrorCode executeCommand(const std::string& command, std::vector<MemoryNode>& memory) {
    Action action = extractAction(command);
    const int idx = command.back() - '0';

    ErrorCode error_code;
    switch (action) {
        case ALLOCATE_SINGLE:
            if (memory[idx].rawMemory == nullptr) {
                memory[idx].rawMemory = new int;
                memory[idx].memoryType = MemoryType::SINGLE;
                error_code = ErrorCode::EXECUTE_SUCCESS;
            } else {
                error_code = ErrorCode::MEMORY_LEAK;
            }
            break;

        case ALLOCATE_MULTIPLE:
            if (memory[idx].rawMemory == nullptr) {
                memory[idx].rawMemory = new int[ALLOCATION_MULTIPLE_SIZE];
                memory[idx].memoryType = MemoryType::MULTIPLE;
                error_code = ErrorCode::EXECUTE_SUCCESS;
            } else {
                error_code = ErrorCode::MEMORY_LEAK;
            }
            break;
        
        case DEALLOCATE_SINGLE:
            if (memory[idx].rawMemory != nullptr) {
                if (memory[idx].memoryType == MemoryType::SINGLE) {
                    delete memory[idx].rawMemory;
                    memory[idx].rawMemory = nullptr;
                    memory[idx].memoryType = MemoryType::UNKNOWN;
                    error_code = ErrorCode::EXECUTE_SUCCESS;
                } else {
                    error_code = ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;
                }
            } else {
                error_code = ErrorCode::DOUBLE_FREE;
            }
            break;

        case DEALLOCATE_MULTIPLE:
            if (memory[idx].rawMemory != nullptr) {
                if (memory[idx].memoryType == MemoryType::MULTIPLE) {
                    delete[] memory[idx].rawMemory;
                    memory[idx].rawMemory = nullptr;
                    memory[idx].memoryType = MemoryType::UNKNOWN;
                    error_code = ErrorCode::EXECUTE_SUCCESS;
                } else {
                    error_code = ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH;
                }
            } else {
                error_code = ErrorCode::DOUBLE_FREE;
            }
            break;
        
        default:
            break;
    }

    return error_code;
}

void printResult(const ErrorCode errorCode, const std::string& command) {
    std::cout << command << " - ";

    switch (errorCode) {
        case ErrorCode::EXECUTE_SUCCESS:
            std::cout << "success";
            break;

        case ErrorCode::MEMORY_LEAK:
            std::cout << "memory leak prevented, will not make allocation";
            break;

        case ErrorCode::DOUBLE_FREE:
            std::cout << "system crash prevented, will skip this deallocation";
            break;

        case ErrorCode::ALLOCATE_DEALLOCATE_MISMATCH:
            std::cout << "Warning allocate/deallocate mismatch, will skip this deallocation";
            break;

        default:
            std::cerr << "Warning, received unknown ErrorCode: " << errorCode << std::endl;
            break;
    }

    std::cout << std::endl;
}
