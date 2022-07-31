#ifndef MAKECOMPANY_H
#define MAKECOMPANY_H

#include <vector>
#include <string>
#include <memory>

#include "Company.h"

enum CompanyFields {
    COMPANY_ID, COMPANY_NAME, EMPLOYEES_ID
};

std::shared_ptr<Company> makeCompany(const std::vector<std::string>& properties) {
    const int companyId = std::stoi(properties[COMPANY_ID]);
    const std::string companyName = properties[COMPANY_NAME];
    std::vector<std::pair<char, char>> employeesVec;

    const size_t size = properties.size();
    for (size_t i = 2; i < size; i++) {
        std::string currEmployeeInits = properties[i];
        employeesVec.emplace_back(currEmployeeInits[0], currEmployeeInits[1]);
    }

    std::shared_ptr<Company> result(new Company(companyId, companyName, employeesVec));
    // std::shared_ptr<Company> result = std::make_shared<Company>(companyId, companyName, employeesVec);

    return result;    
}

#endif // !MAKECOMPANY_H
