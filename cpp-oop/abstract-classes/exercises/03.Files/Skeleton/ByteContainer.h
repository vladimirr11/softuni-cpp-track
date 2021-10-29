#ifndef BYTECONTAINER_H
#define BYTECONTAINER_H

#include <string>

class ByteContainer {
public:
    virtual std::string getBytes() = 0;

    virtual ~ByteContainer() {}
};

#endif // !BYTECONTAINER_H
