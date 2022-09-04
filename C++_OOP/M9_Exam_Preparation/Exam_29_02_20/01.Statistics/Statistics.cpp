#include "Statistics.h"

void Statistics::printStatistics() {
    std::cout << "Elders data:" << std::endl;
    std::sort(eldersVec.begin(), eldersVec.end(), [](const PersonInfo& p1, const PersonInfo& p2) {
        return p1.age > p2.age;
    });
    for (const auto& elder : eldersVec) {
        std::cout << elder.firstName << " " << elder.lastName << " " << elder.height << std::endl;
    }

    std::cout << "Adults data:" << std::endl;
    std::sort(adultsVec.begin(), adultsVec.end(), [](const PersonInfo& p1, const PersonInfo& p2) {
        return p1.age < p2.age;
    });
    for (const auto& adult : adultsVec) {
        std::cout << adult.firstName << " " << adult.lastName << " " << adult.height << std::endl;
    }

    std::cout << "Minors data:" << std::endl;
    std::sort(minorsVec.begin(), minorsVec.end(), [](const PersonInfo& p1, const PersonInfo& p2) {
        return p1.age < p2.age;
    });
    for (const auto& minor : minorsVec) {
        std::cout << minor.firstName << " " << minor.lastName << " " << minor.height << std::endl;
    }
}

Statistics& operator<<(Statistics& stat, PersonInfo& info) {
    if (info.age <= 18) {
        stat.minorsVec.push_back(info);
    } else if (info.age >= 63) {
        stat.eldersVec.push_back(info);
    } else {
        stat.adultsVec.push_back(info);
    }

    return stat;
}
