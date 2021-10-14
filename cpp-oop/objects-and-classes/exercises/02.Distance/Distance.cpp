#include <iostream>
#include <cmath>

class Point {
public:
    Point() : _x(0), _y(0) {}

    Point(int inputX, int inputY) : _x(inputX), _y(inputY) {}

    void readInputCoords() {
        int inx = 0, iny = 0;
        std::cin >> inx >> iny;
        _x = inx; 
        _y = iny; 
    }

    void calcEuclideanDist(Point& secPoint) {
        _eucDistance = std::sqrt(pow(secPoint._x - _x, 2) + pow(secPoint._y - _y, 2));
    }

    void printEuclideanDist() {
        std::cout.setf(std::ios::fixed);
        std::cout.precision(3);
        std::cout << _eucDistance << std::endl;
    }
    
private:
    double _eucDistance;
    int _x;
    int _y;
};

int main() {
    Point point1;
    point1.readInputCoords();

    Point point2;
    point2.readInputCoords();

    point1.calcEuclideanDist(point2);
    
    point1.printEuclideanDist();
    
    return 0;
}
