#ifndef PRINTUTILS_H
#define PRINTUTILS_H

template<typename Type>
void printVector(const std::vector<Type>& vec) {
    typename std::vector<Type>::const_iterator it;
    for (it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

#endif // !PRINTUTILS_H
