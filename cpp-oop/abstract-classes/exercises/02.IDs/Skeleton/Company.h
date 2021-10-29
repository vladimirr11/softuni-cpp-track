#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <vector>
#include <sstream>

#include "HasInfo.h"
#include "HasId.h"

class Company : public HasId, public HasInfo {
public:
    Company();

    Company(int id, std::string name, std::vector<std::pair<char, char>> employees);

    int getId() const;

    std::string getName() const;

    std::vector<std::pair<char, char>> getEmployees() const;

    std::string getInfo() const;

    friend std::ostream& operator<<(std::ostream& stream, const Company& c);

    friend std::istream& operator>>(std::istream& stream, Company& c);

private:
    int id;
    std::string name;
    std::vector<std::pair<char, char>> employees;
};

#endif // !COMPANY_H
