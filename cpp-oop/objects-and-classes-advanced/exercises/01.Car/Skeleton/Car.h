#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car {
public:
    Car(std::string brand, std::string model, int year) : 
        _brand(brand), _model(model), _year(year) {}
    
    std::string GetBrand() const {
        return this->_brand;
    }

    std::string GetModel() const {
        return this->_model;
    }

    int GetYear() const {
        return this->_year;
    }
    
private:
    std::string _brand;
    std::string _model;
    int _year = 0;
};

#endif // !CAR_H
