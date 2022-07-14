#include "Rust.h"

int main() {
    MetalField mfield;
    mfield.read(std::cin);

    Rust rust;
    rust.readRustTime(std::cin);

    rust.spreadRust(mfield, rust.getRustTime());

    std::cout << mfield.print();

    return 0;
}
