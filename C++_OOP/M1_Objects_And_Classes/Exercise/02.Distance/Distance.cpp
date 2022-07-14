#include <iostream>
#include <iomanip>
#include <cmath>

class Point {
public:
    Point() : _x(0), _y(0) {}

    void read(std::istream& istr);

    double calcEuclideanDist(Point& secPoint);

private:
    int _x;
    int _y;
};

void Point::read(std::istream& istr) {
    istr >> _x >> _y;
}

double Point::calcEuclideanDist(Point& secPoint) {
    return std::sqrt(pow(_x - secPoint._x, 2) + pow(_y - secPoint._y, 2));
}

int main() {
    Point point1;
    point1.read(std::cin);

    Point point2;
    point2.read(std::cin);

    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(3) << point1.calcEuclideanDist(point2) << std::endl;
    
    return 0;
}
