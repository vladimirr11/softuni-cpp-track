#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <vector>

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"

class Directory : public FileSystemObjectsContainer, public FileSystemObject {
public:
    Directory(const std::string& directoryName) : FileSystemObject(directoryName) {}

    void add(const std::shared_ptr<FileSystemObject>& obj) final {
        _dirObjects.push_back(obj);
    }

    size_t getSize() const final {
        size_t size = 0;
        for (const auto& obj : _dirObjects) {
            size += obj->getSize();
        }
        
        return size;
    }

private:
    std::vector<std::shared_ptr<FileSystemObject>> _dirObjects;
};

#endif // !DIRECTORY_H
