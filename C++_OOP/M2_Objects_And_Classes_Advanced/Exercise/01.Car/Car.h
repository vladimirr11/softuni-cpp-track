#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car {
public:
    Car(string brand, string model, int year) : 
        _brand(brand), _model(model), _year(year) {}
    
    string GetBrand() const {
        return this->_brand;
    }

    string GetModel() const {
        return this->_model;
    }

    int GetYear() const {
        return this->_year;
    }
    
private:
    string _brand;
    string _model;
    int _year = 0;
};

#endif // !CAR_H
