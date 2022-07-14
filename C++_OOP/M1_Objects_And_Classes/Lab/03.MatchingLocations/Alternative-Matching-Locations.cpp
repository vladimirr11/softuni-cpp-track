#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

const std::string STOP_READ_DEL = ".";

using Coordinates = std::vector<std::string>;
using Queries = std::vector<std::string>;

class Query;

class GeoCoordinates {
public:
    void read(std::istream& istr);

    std::string getCoordinates(const Query& query) const;

private:
    Coordinates coords;
};

class Query {
public:
    Query() = default;

    void read(std::istream& istr);

    Queries getQueries() const { return queries; }

private:
    Queries queries;
};

void GeoCoordinates::read(std::istream& istr) {
    std::string coord;
    while (true) {
        std::getline(istr, coord);
        if (coord == STOP_READ_DEL) {
            break;
        }
        coords.push_back(coord);
    }
}

void Query::read(std::istream& istr) {
    std::string query;
    while (true) {
        std::getline(istr, query);
        if (query == STOP_READ_DEL) {
            break;
        }
        if (query.find(' ') != std::string::npos) {
            queries.push_back(query.substr(0, query.find(' ')));
        } else {
            queries.push_back(query);
        }
    }
}    

std::string GeoCoordinates::getCoordinates(const Query& q) const {
    std::ostringstream ostream;
    Queries queries = q.getQueries();
    for (const auto& query : queries) {
        for (const auto& coord : coords) {
            if (coord.find(query) != std::string::npos) {
                ostream << coord << std::endl;
            }
        }
    }

    return ostream.str();
}

int main() {    
    GeoCoordinates coords;
    coords.read(std::cin);

    Query queries;
    queries.read(std::cin);

    std::cout << coords.getCoordinates(queries);

    return 0;
}
