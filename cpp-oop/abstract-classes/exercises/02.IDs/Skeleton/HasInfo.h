#ifndef HASINFO_H
#define HASINFO_H

#include <string>

class HasInfo {
public:
    virtual std::string getInfo() const {
        return info;
    }

    virtual ~HasInfo() {}

private: 
    std::string info;
};

#endif // !HASINFO_H
