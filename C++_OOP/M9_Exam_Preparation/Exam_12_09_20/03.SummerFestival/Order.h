#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>

class Order {
public:
    Order();

    Order(std::string type, std::string size, double price);

    void printOrderInfo();

    Order(const Order& other);

    std::string getType() const;

    std::string getSize() const;

    double getPrice() const;

    void setType(std::string type);

    void setSize(std::string size);

    void setPrice(double price);

    Order& operator=(const Order& other);

    ~Order();

private:
    std::string type;
    std::string size;
    double price;
};

#endif // !ORDER_H
