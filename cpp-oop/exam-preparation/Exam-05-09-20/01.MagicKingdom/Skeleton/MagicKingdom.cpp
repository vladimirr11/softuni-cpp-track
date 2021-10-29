#include "MagicKingdom.h"

void MagicKingdom::printAll() {
    std::cout << "Anti-Mages:" << std::endl;
    std::sort(antiMagsVec.begin(), antiMagsVec.end(), [](const Villager& v1, const Villager& v2) {
        return v1.power < v2.power;
    });
    for (const auto& antiMag : antiMagsVec) {
        std::cout << antiMag.name << " - " << antiMag.magicItem << std::endl;
    }

    std::cout << "Commoners:" << std::endl;
    std::sort(commonerVec.begin(), commonerVec.end(), [](const Villager& v1, const Villager& v2) {
        return v1.power > v2.power;
    });
    for (const auto& commoner : commonerVec) {
        std::cout << commoner.name << " - " << commoner.magicItem << std::endl;
    }

    std::cout << "Mages:" << std::endl;
    std::sort(magiciansVec.begin(), magiciansVec.end(), [](const Villager& v1, const Villager& v2) {
        return v1.power > v2.power;
    });
    for (const auto& mag : magiciansVec) {
        std::cout << mag.name << " - " << mag.magicItem << std::endl;
    }
}

MagicKingdom& operator<<(MagicKingdom& mKingdom, Villager& villager) {
    if (villager.power < 0) {
        mKingdom.antiMagsVec.push_back(villager);
    } else if (villager.power > 99) {
        mKingdom.magiciansVec.push_back(villager);
    } else {
        mKingdom.commonerVec.push_back(villager);
    }

    return mKingdom;
}
