#include <iostream>
#include <cmath>

int main() {
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    const int exponent = 2;

    std::cin >> a >> b >> c;
    
    double discriminant = pow(b, exponent) - (4 * a * c);

    if (discriminant < 0) {
        std::cout << "no roots" << std::endl;
    } else if (discriminant == 0) {
        double root = - (b / (2 * a));
        std::cout << root << std::endl;
    } else {
        double rootOne = (-b - sqrt(discriminant)) / (2 * a);
        double rootTwo = (-b + sqrt(discriminant)) / (2 * a);

        std::cout << rootTwo << " " << rootOne << std::endl;
    }

    return 0;
}
