#ifndef PROFITREPORT_H
#define PROFITREPORT_H

#include <iostream>
#include <map>
#include <string>

#include "Company.h"
#include "ProfitCalculator.h"

std::string getProfitReport(Company* firstCompanyPtr, Company* lastCompanyPtr, 
                                   std::map<int, ProfitCalculator>& profitCalculatorMap) {

    std::ostringstream outStream;
    
    for (Company* currCompanyPtr = firstCompanyPtr; currCompanyPtr <= lastCompanyPtr; currCompanyPtr++) {
        const int currCompanyId = currCompanyPtr->getId();
        ProfitCalculator currProfitCalculator = profitCalculatorMap[currCompanyId];
        const int currCompanyProfit = currProfitCalculator.calculateProfit(*currCompanyPtr);

        outStream << currCompanyPtr->getName() << " = " << currCompanyProfit << std::endl;
    }

    return outStream.str();
}

// std::ostream& operator<<(std::ostream& stream, std::ostringstream oStrStream) {
//     return stream << oStrStream.str();
// }

#endif // !PROFITREPORT_H
