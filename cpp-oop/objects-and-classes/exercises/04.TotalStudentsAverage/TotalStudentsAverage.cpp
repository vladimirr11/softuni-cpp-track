#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>

const int ARR_FILDS = 3;

class Student {
public:
    std::string sName;
    std::string sSurname;
    double average;

public:
    Student() : average(0) {}

    Student(std::array<std::string, ARR_FILDS>& studentInfoArr) {
        this->sName = studentInfoArr[0];
        this->sSurname = studentInfoArr[1];
        this->average = std::stod(studentInfoArr[2]);
    }

    void printStudentInfo() {
        std::cout << sName << " " << sSurname << " " << average << std::endl;
    }

};

std::vector<Student> getInput() {
    int numStudents = 0;
    std::cin >> numStudents;
    std::cin.ignore();

    std::vector<Student> inputVec;
    inputVec.reserve(numStudents);

    for (int i = 0; i < numStudents; i++) {
        Student currStudent;

        getline(std::cin, currStudent.sName);
        getline(std::cin, currStudent.sSurname);

        std::cin >> currStudent.average;
        std::cin.ignore();

        inputVec.push_back(currStudent);
    }

    return inputVec;
}

void calcAverageStudentsGrade(std::vector<Student>& studentsVec) {
    if (studentsVec.empty()) {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    double totalAverage = 0;
    for (Student& student : studentsVec) {
        totalAverage += student.average;
    }

    size_t vecLen = studentsVec.size();

    totalAverage /= vecLen;

    std::cout << totalAverage << std::endl;
}

int main() {
    std::vector<Student> students = getInput();

    for (Student& student : students) {
        student.printStudentInfo();
    }

    calcAverageStudentsGrade(students);

    return 0;
}
