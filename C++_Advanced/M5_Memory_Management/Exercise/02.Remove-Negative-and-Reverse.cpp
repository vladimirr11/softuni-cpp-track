#include <iostream>
#include <string>
#include <sstream>

int* getInputNums(int& size) {
    std::string iline;
    std::getline(std::cin >> std::ws, iline);
    std::istringstream istr(iline);

    int* nums = new int[1000]{};

    int currNum {};
    while (istr >> currNum) {
        if (currNum > 0) {
            nums[size] = currNum;
            size++;
        }
    }

    return nums;
}

int main() {
    int size {};
    int* nums = getInputNums(size);

    if (size == 0) {
        std::cout << "empty" << std::endl;
    }

    for (int i = size - 1; i >= 0; i--) {
        std::cout << nums[i] << " ";
    }

    std::cout << std::endl;
    delete[] nums;

    return 0;
}
