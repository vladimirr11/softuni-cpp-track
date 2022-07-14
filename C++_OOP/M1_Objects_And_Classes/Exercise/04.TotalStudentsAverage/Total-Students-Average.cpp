#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Student {
public:
    Student() = default;

    void read(std::istream& istr);

    const std::string print() const;

    std::string getName() const { return name; }

    std::string getSurname() const { return surname; }

    double getAverage() const { return average; }

private:
    std::string name;
    std::string surname;
    double average{};
};

void Student::read(std::istream& istr) {
    istr >> name >> surname >> average;
}

const std::string Student::print() const {
    std::ostringstream ostr;
    ostr << name << " " << surname << " " << average << std::endl;
    return ostr.str();
}

void getStudents(std::vector<Student>& students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        students[i].read(std::cin);
    }
}

double calcTotalAverage(const std::vector<Student>& students) {
    double totalAverg {};
    size_t studSize = students.size();
    for (int i = 0; i < studSize; i++) {
        totalAverg += students[i].getAverage();
    }

    return totalAverg / studSize;
}

void printStudents(const std::vector<Student>& students) {
    size_t studSize = students.size();
    for (int i = 0; i < studSize; i++) {
        std::cout << students[i].print();
    }
}

int main() {
    int numStudents {};
    std::cin >> numStudents;
    std::cin.ignore();

    std::vector<Student> students;

    if (numStudents > 0) {
        students.resize(numStudents);
        getStudents(students, numStudents);
        printStudents(students);
        double totalAverg = calcTotalAverage(students);
        std::cout << totalAverg << std::endl;
    } else {
        std::cout << "Invalid input" << std::endl;
    }

    return 0;
}
