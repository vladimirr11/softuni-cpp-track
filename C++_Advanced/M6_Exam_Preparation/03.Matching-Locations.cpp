#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <sstream>
#include <map>

const int CITY_IDX = 0;
const int LATITUDE_IDX = 1;
const int LONGITUDE_IDX = 2;

const int ARR_SIZE = 3;

const std::string STOP_READ_DEL = ".";
const char COORDS_DELIMITER = ',';


std::vector<std::array<std::string, ARR_SIZE>> readInputCoordinates() {
    std::vector<std::array<std::string, ARR_SIZE>> coordsVec {};

    std::array<std::string, ARR_SIZE> coords {};
    while (true) {
        std::string line;
        getline(std::cin, line);

        if (line == STOP_READ_DEL) {
            break;
        }

        std::istringstream istream(line);

        getline(istream, coords[CITY_IDX], COORDS_DELIMITER);
        getline(istream, coords[LATITUDE_IDX], COORDS_DELIMITER);
        getline(istream, coords[LONGITUDE_IDX], COORDS_DELIMITER);

        coordsVec.push_back(coords);
    }

    return coordsVec;
}

std::vector<std::string> readQuery() {
    std::vector<std::string> queryVec {};
    while (true) {
        std::string line;
        getline(std::cin, line);
        if (line == STOP_READ_DEL) {
            break;
        }
        queryVec.push_back(line);
    }

    return queryVec;
}

void findCoordsOfQueryAndPrintResult(std::vector<std::array<std::string, ARR_SIZE>>& coordsVec,
                                     std::vector<std::string>& queryVec) {
    for (auto query : queryVec) {
        std::size_t found = query.find(STOP_READ_DEL);

        std::string latCoords;
        std::string longCoords;
        if (found != std::string::npos) {
            std::istringstream istr(query);
            istr >> latCoords >> longCoords;
            for (auto arr : coordsVec) {
                if (arr[LATITUDE_IDX] == latCoords && arr[LONGITUDE_IDX] == longCoords) {
                    std::cout << arr[CITY_IDX] << "," << arr[LATITUDE_IDX] << "," << arr[LONGITUDE_IDX] << std::endl;
                }
            }
        } else {
            for (auto arr : coordsVec) {
                if (arr[CITY_IDX] == query) {
                    std::cout << arr[CITY_IDX] << "," << arr[LATITUDE_IDX] << "," << arr[LONGITUDE_IDX] << std::endl;
                }
            }
        }
    }
}

int main() {
    std::vector<std::array<std::string, ARR_SIZE>> coordsVec = readInputCoordinates();
    std::vector<std::string> queryVec = readQuery();
    
    findCoordsOfQueryAndPrintResult(coordsVec, queryVec);

    return 0; 
}
