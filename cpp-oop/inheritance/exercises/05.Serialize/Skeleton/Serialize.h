#ifndef SERIALIZE_H
#define SERIALIZE_H

#include "Company.h"

byte* serializeToMemory(std::string input, size_t& bytesWritten) {
    std::istringstream companiesInputStream(input);

    std::vector<Company> companiesVec;
    Company currCompany;
    while (companiesInputStream >> currCompany) {
        companiesVec.push_back(currCompany);
    }

    std::vector<byte> bytesVec;
    
    bytesVec.push_back(companiesVec.size());

    for (const Company& c : companiesVec) {
        bytesVec.push_back(c.getId());

        for (char c : c.getName()) {
            bytesVec.push_back(static_cast<byte>(c));
        }

        bytesVec.push_back('\0');
        bytesVec.push_back(c.getEmployees().size());

        for (const auto& employeeInits : c.getEmployees()) {
            bytesVec.push_back(static_cast<byte>(employeeInits.first));
            bytesVec.push_back(static_cast<byte>(employeeInits.second));
        }
    }

    bytesWritten = bytesVec.size();
    byte* memory = new byte[bytesWritten];
    for (size_t i = 0; i < bytesWritten; i++) {
        memory[i] = bytesVec[i];
    }

    return memory;
}

#endif // !SERIALIZE_H
