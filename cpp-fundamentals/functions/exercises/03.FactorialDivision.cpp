#include <iostream>

double claculateFactorial(const int& numOne, const int& numTwo) {
    unsigned long long factorialNumOne = 1;
    unsigned long long factorialNumTwo = 1;

    for (int i = 1; i <= numOne; i++) {
        factorialNumOne *= i;
    }

    for (int i = 1; i <= numTwo; i++) {
        factorialNumTwo *= i;
    }

    return factorialNumOne / (double)factorialNumTwo;

}


int main() {
    int numOne = 0;
    int numTwo = 0;

    std::cin >> numOne >> numTwo;

    double result = claculateFactorial(numOne, numTwo);

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    std::cout << result << std::endl;

    return 0;
}