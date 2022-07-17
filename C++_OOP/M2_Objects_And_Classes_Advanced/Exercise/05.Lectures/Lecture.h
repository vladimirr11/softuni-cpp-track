#ifndef LECTURE_H
#define LECTURE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

#include "Resource.h"

namespace SoftUni {

class Lecture {
public:
    using iterator = std::set<Resource>::iterator;

    Lecture() = default;

    iterator begin() {
        return _resourceSet.begin();
    }

    iterator end() {
        return _resourceSet.end();
    }

    int operator[](ResourceType& resType) const {
        return _resourceTypeMap.at(resType);
    }

    void updateResources(const Resource& res) {
        if (_resourceSet.find(res) != _resourceSet.end()) {
            _resourceSet.erase(res);
            _resourceTypeMap[res.getType()]--;
        }

        _resourceSet.insert(res);
        _resourceTypeMap[res.getType()]++;
    }

    std::set<Resource> getResourcesSet() const {
        return _resourceSet;
    }

    std::map<ResourceType, int> getResourceTypeMap() const {
        return _resourceTypeMap;
    }

    friend Lecture& operator<<(Lecture& lecture, const Resource& resource);

    friend std::vector<ResourceType>& operator<<(std::vector<ResourceType>& resType, const Lecture& lecture);                

private:
    std::map<ResourceType, int> _resourceTypeMap;
    std::set<Resource> _resourceSet;
};

Lecture& operator<<(Lecture& lecture, const Resource& resource) {
    lecture.updateResources(resource);
    return lecture;
}

std::vector<ResourceType>& operator<<(std::vector<ResourceType>& resTypesVec, Lecture& lecture) {
    for (const auto& pair : lecture.getResourceTypeMap()) {
        resTypesVec.push_back(pair.first);
    }
    return resTypesVec;
}

}

#endif // !LECTURE_H
