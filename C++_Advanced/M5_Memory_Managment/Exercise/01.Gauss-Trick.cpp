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
        nums[size] = currNum;
        size++;
    }

    return nums;
}

int main() {
    int size {};
    int* nums = getInputNums(size);

    int halfNumsSize {};
    size % 2 == 0 ? halfNumsSize = size / 2: halfNumsSize = (size / 2) + 1;
    for (int i = 0; i < halfNumsSize; i++) {
        if (i == ((size - 1) - i)) {
            std::cout << nums[i];
        } else {
            std::cout << nums[i] + nums[(size - 1) - i] << " ";
        }
    }
    
    std::cout << std::endl;

    delete[] nums;

    return 0;
}
