#include <iostream>
#include <list>

int main() {
    std::list<int> numbers {1, 3, 5};

    std::list<int>::iterator lastItemIter = numbers.end();
    lastItemIter--; // points to 5 now
    numbers.insert(lastItemIter, 4);

    numbers.push_back(6);

    std::list<int>::iterator secondItemIter = numbers.begin(); // points to 1
    secondItemIter++; // points to 3 now
    numbers.insert(secondItemIter, 2);

    numbers.insert(numbers.begin(), 0);

    // prints 0 1 2 3 4 5 6
    for (int number : numbers) {
        std::cout << number << " ";
    }

    return 0;
}
