#include "Scientist.h"

#include <cstring>

Scientist::Scientist() {}

Scientist::Scientist(char* name, int discoveriesCount) 
    : name(name), discoveriesCount(discoveriesCount) {}

Scientist::Scientist(const Scientist& other) {
    int len = strlen(other.name);

    name = new char[len + 1];

    for (int i = 0; i < len; i++) {
        name[i] = other.name[i];
    }
    name[len] = '\0';

    this->discoveriesCount = discoveriesCount;
};

Scientist& Scientist::operator=(const Scientist& other) {
    if (this != &other) {
        int len = strlen(other.name);

        name = new char[len + 1];

        for (int i = 0; i < len; i++) {
            name[i] = other.name[i];
        }
        name[len] = '\0';

        this->discoveriesCount = discoveriesCount;
    }

    return *this;
}

Scientist::~Scientist() {
    if (name) {
        delete[] name;
        name = nullptr;
    }
}

char* Scientist::getName() const {
    return this->name;
}

int Scientist::getDiscoveriesCount() const {
    return this->discoveriesCount;
}

void Scientist::setName(const char* name) {
    this->name = (char*)name;
}

void Scientist::setDiscoveriesCount(int count) {
    this->discoveriesCount = discoveriesCount;
}

void Scientist::Print() const {}
