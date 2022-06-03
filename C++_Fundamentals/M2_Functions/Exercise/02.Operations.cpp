#include <iostream>

double add(double numOne, double numTwo) {
    return numOne + numTwo;
}

double multiply(double numOne, double numTwo) {
    return numOne * numTwo;
}

double subtract(double numOne, double numTwo) {
    return numOne - numTwo;
}

double divide(double numOne, double numTwo) {
    if (numTwo == 0) {
        std::cout << "Can't divide by zero." << std::endl;
        return;
    }

    return numOne / numTwo;
}

int main() {
    double numOne = 0.0;
    double numTwo = 0.0;
    char oprtr;

    std::cin >> numOne >> numTwo;
    std::cin >> oprtr;

    if (oprtr == '+') {
       double num = add(numOne, numTwo);
       std::cout << num << std::endl;
    } else if (oprtr == '*') {
        double num = multiply(numOne, numTwo);
        std::cout << num << std::endl;
    } else if (oprtr == '-') {
        double num = subtract(numOne, numTwo);
        std::cout << num << std::endl;
    } else if (oprtr == '/') {
        double num = divide(numOne, numTwo);
        if (numTwo != 0) {
            std::cout << num << std::endl;
        }
    }

    return 0;
}
