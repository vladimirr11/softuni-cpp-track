#ifndef PRINTUTILS_H
#define PRINTUTILS_H

template<typename Cont>
void printContainer(typename Cont::iterator first, typename Cont::iterator last) {
    while (first != last) {
        std::cout << *first++ << " ";
    }
    std::cout << std::endl;
}

#endif // !PRINTUTILS_H
