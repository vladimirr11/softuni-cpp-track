#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

std::map<std::string, std::vector<double>> getStudentsGrades() {
    int studentsNumber = 0;
    std::cin >> studentsNumber;
    std::cin.ignore();

    std::map<std::string, std::vector<double>> studentsGrades {};

    for (int i = 0; i < studentsNumber; i++) {
        std::string iLine;
        getline(std::cin, iLine);
        std::istringstream iStream(iLine);
        
        std::string studentName;
        double grade = 0.0;

        iStream >> studentName >> grade;
        studentsGrades[studentName].push_back(grade);
    }

    return studentsGrades;
}

int main() {
    std::map<std::string, std::vector<double>> studentsGradesMap = getStudentsGrades();

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    for (const auto& it : studentsGradesMap) {
        std::cout << it.first << " -> ";

        double averageGrade {};
        for (const auto& grade : it.second) {
            averageGrade += grade; 
            std::cout << grade << " ";
        } 

        std::cout << "(avg: " << averageGrade / it.second.size() << ")" << std::endl;
    }

    return 0;
}
