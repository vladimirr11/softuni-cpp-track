#include <iostream>
#include <string>
#include <vector>
#include <memory>

class IntArray {
    std::shared_ptr<int> data;
    int size;
public:
    // IntArray(int size) : data(new int[size], [](int* p) { delete[] p; }), size(size) {} 
    IntArray(int size) : data(new int[size], std::default_delete<int[]>()), size(size) {}

    int getSize() const {
        return size;
    }

    int& operator[](const int index) const {
        return data.get()[index];
    }
};

int main() {
    while (true) {
        // no memory leak
        IntArray arr(10);
        arr[0] = 42;
        arr = arr;
        std::cout << arr[0] << std::endl;
    }

    return 0;
}
