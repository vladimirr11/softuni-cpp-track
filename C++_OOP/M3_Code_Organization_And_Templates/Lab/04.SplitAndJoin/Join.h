#ifndef JOIN_H
#define JOIN_H

#include <string>
#include <vector>
#include <sstream>

template<typename Type>
std::string join(std::vector<Type>& vec, const std::string& joinStr) {
    std::ostringstream joined;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        auto copyIt = it;
        if (++copyIt == vec.end()) {
            joined << *it;
        } else {
            joined << *it << joinStr;
        }
    }
    // joined.seekp(joinStr.size() * -1, std::ios_base::end);
    // joined << "\n";
    return joined.str();
}

#endif // !JOIN_H
