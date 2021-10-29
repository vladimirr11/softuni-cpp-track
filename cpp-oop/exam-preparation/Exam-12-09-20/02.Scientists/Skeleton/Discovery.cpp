#include "Discovery.h"

#include <cstring>

Discovery::Discovery() {}

Discovery::Discovery(const char* discoveryName, int year, const Scientist& scientistName, Fields fieldOfStudy) :
        discoveryName(const_cast<char*>(discoveryName)), 
        year(year), scientist(scientistName), fieldOfStudy(fieldOfStudy) {}

Discovery::Discovery(const Discovery& other) {
    int len = strlen(other.discoveryName);

    discoveryName = new char[len + 1];

    for (int i = 0; i < len; i++) {
        discoveryName[i] = other.discoveryName[i];
    }
    discoveryName[len] = '\0';

    this->year = other.year;
    this->scientist = other.scientist;
    this->fieldOfStudy = other.fieldOfStudy;
}

char* Discovery::getDiscoveryName() const {
    return discoveryName;
}

int Discovery::getYear() const {
    return year;
}

Scientist Discovery::getScientist() const {
    return scientist;
}

Fields Discovery::getFieldOfStudy() const {
    return fieldOfStudy;
}

void Discovery::setDiscoveryName(const char* name) {
    this->discoveryName = const_cast<char*>(name);
}

void Discovery::setYear(int year) {
    this->year = year;
}

void Discovery::setScientist(const Scientist& author) {
    this->scientist = author;
}

void Discovery::setFieldOfStudy(Fields fieldOfStudy) {
    this->fieldOfStudy = fieldOfStudy;
}

char* Discovery::getScientistName() const {
    return this->scientist.getName();
}

Discovery& Discovery::operator=(const Discovery& other) {
    if (this != &other) {
        int len = strlen(other.discoveryName);

        discoveryName = new char[len + 1];

        for (int i = 0; i < len; i++) {
            discoveryName[i] = other.discoveryName[i];
        }
        discoveryName[len] = '\0';

        this->year = other.year;
        this->scientist = other.scientist;
        this->fieldOfStudy = other.fieldOfStudy;
    }

    return *this;
}

Discovery::~Discovery() {
    if (discoveryName) {
        delete[] discoveryName;
        discoveryName = nullptr;
    }
};
