#include <iostream>
#include <cstdlib>

int moduleDivideByTen(long long int& number) {
    return number % 10;
}

int divideByTen(long long int& number) {
    return number / 10;
}

int convertNumber(long long int& number) {
    return abs(number);
}

void printNumber(int number) {
    std::cout << number << std::endl;
}

int main() {
    long long int number = 0;
    std::cin >> number;

    int evens = 0;
    int odds = 0;
    int counter = 0;

    if (number < 0) {
        number = convertNumber(number);
    } 
    
    if (number < 10 || number < -10) {
        printNumber(number);
        return 0;
    }

    while (number > 0) {
        counter += 1;
        int remainderNumber = moduleDivideByTen(number);

        (counter % 2 == 1) ? evens += remainderNumber: odds += remainderNumber;

        number = divideByTen(number);
    }

    int result = evens * odds;

    printNumber(result);

    return 0;
}
