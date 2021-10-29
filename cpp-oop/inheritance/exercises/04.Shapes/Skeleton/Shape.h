#ifndef SHAPE_H
#define SHAPE_H

#include <iomanip>

#include "Vector2D.h"

class Shape {
public:
    Shape() : area(0), _center(0, 0) {}

    Shape(const Vector2D& center) : area(0), _center(center) {}

    Vector2D getCenter() const {
        return this->_center;
    }

    double getArea() const {
        return this->area;
    }

protected:
    double area;

private:
    Vector2D _center;
};

#endif // !SHAPE_H
