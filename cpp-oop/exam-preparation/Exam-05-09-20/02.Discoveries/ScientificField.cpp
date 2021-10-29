#include "ScientificField.h"

void ScientificField::print() {
    std::cout << "Physics:" << std::endl;
    std::sort(physicsVec.begin(), physicsVec.end(), [](const Discovery& d1, const Discovery& d2) {
        return d1.year < d2.year;
    });
    for (const auto& physics : physicsVec) {
        std::cout << physics.name << " " << physics.year << " - " << physics.scientistName << std::endl;
    }

    std::cout << "Linguistics:" << std::endl;
    std::sort(linguisticsVec.begin(), linguisticsVec.end(), [](const Discovery& d1, const Discovery& d2) {
        return d1.year < d2.year;
    });
    for (const auto& ling : linguisticsVec) {
        std::cout << ling.name << " " << ling.year << " - " << ling.scientistName << std::endl;
    }

    std::cout << "Philosophy:" << std::endl;
    std::sort(philosophyVec.begin(), philosophyVec.end(), [](const Discovery& d1, const Discovery& d2) {
        return d1.year < d2.year;
    });
    for (const auto& philosophy : philosophyVec) {
        std::cout << philosophy.name << " " << philosophy.year << " - " << philosophy.scientistName << std::endl;
    }

    std::cout << "Chemistry:" << std::endl;
    std::sort(chemistryVec.begin(), chemistryVec.end(), [](const Discovery& d1, const Discovery& d2) {
        return d1.year < d2.year;
    });
    for (const auto& chem : chemistryVec) {
        std::cout << chem.name << " " << chem.year << " - " << chem.scientistName << std::endl;
    }
}

ScientificField& operator<<(ScientificField& sField, Discovery& discovery) {
    if (discovery.fieldType == 1) {
        sField.philosophyVec.push_back(discovery);
    } else if (discovery.fieldType == 2) {
        sField.linguisticsVec.push_back(discovery);
    } else if (discovery.fieldType == 3) {
        sField.physicsVec.push_back(discovery);
    } else if (discovery.fieldType == 4) {
        sField.chemistryVec.push_back(discovery);
    }

    return sField;
}
