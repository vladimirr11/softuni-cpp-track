#ifndef FILE_H
#define FILE_H

#include <string>

#include "FileSystemObject.h"
#include "ByteContainer.h"

class File : public FileSystemObject, public ByteContainer {
public:
    File(const std::string& fileName, const std::string& content) :
        FileSystemObject(fileName), _content(content) {}
    
    size_t getSize() const {
        return _content.size();
    }

    std::string getBytes() final {
        return _content;
    }

private:
    std::string _content;
};

#endif // !FILE_H
