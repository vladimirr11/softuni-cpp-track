#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <string>
#include <vector>

#include "ResourceType.h"

namespace SoftUni {

class Resource {
public:
    Resource() = default;

    Resource(int id, ResourceType resourceType, std::string link) :
        _id(id), _resourceType(resourceType), _link(link) {}

    int getId() const {
        return this->_id;
    }

    ResourceType getType() const {
        return _resourceType;
    }

    std::string getLink() const {
        return this->_link;
    }

    friend std::ostream& operator<<(std::ostream& outputStream, const Resource& resource);

    friend std::istream& operator>>(std::istream& iStream, Resource& resource);

    friend bool operator<(const Resource& leftRes, const Resource& rightRes);

private:
    int _id = 0;
    ResourceType _resourceType;
    std::string _link;
};

std::ostream& operator<<(std::ostream& outputStream, const Resource& resource) {
    return outputStream << resource.getId() << " " << resource.getType() << " " << resource.getLink();
}   

std::istream& operator>>(std::istream& inputStream, Resource& resource) {
    std::string typeString;
    inputStream >> resource._id >> typeString >> resource._link;
    
    if (typeString == "Presentation") {
        resource._resourceType = PRESENTATION;
    } else if (typeString == "Demo") {
        resource._resourceType = DEMO;
    } else if (typeString == "Video") {
        resource._resourceType = VIDEO;
    } else {
        std::cerr << "Unsopported type " << typeString << std::endl;
    }

    return inputStream;
}

bool operator<(const Resource& leftRes, const Resource& rightRes) {
    return leftRes.getId() < rightRes.getId();
}

}

#endif // !RESOURCE_H
