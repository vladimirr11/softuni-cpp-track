#include "DesertEagle.h"

#include <iostream>
#include <math.h>

DesertEagle::DesertEagle(const int damagePerRound, const int clipSize, const int remainingAmmo) 
    : Pistol(damagePerRound, clipSize, remainingAmmo) {}

bool DesertEagle::fire(PlayerVitalData& enemyPlayerData) {
    if (_currClipBullets == 0) {
        Pistol::reload();
        return false;
    }

    _currClipBullets--;

    if (enemyPlayerData.armor) {
        enemyPlayerData.armor -= (_damagePerRound / 4);
        enemyPlayerData.health -= (_damagePerRound * 3 / 4);

        if (enemyPlayerData.armor <= 0) {
            enemyPlayerData.health -= std::abs(enemyPlayerData.armor);

            enemyPlayerData.armor = 0;

            if (enemyPlayerData.health <= 0) {
                std::cout << "Enemy left with: " << enemyPlayerData.health << " health and "
                          << enemyPlayerData.armor << " armor" << std::endl;

                return true;
            }

            std::cout << "Enemy left with: " << enemyPlayerData.health << " health and "
                      << enemyPlayerData.armor << " armor" << std::endl;

            return false;

        } else {
            if (enemyPlayerData.health <= 0) {
                std::cout << "Enemy left with: " << enemyPlayerData.health << " health and "
                          << enemyPlayerData.armor << " armor" << std::endl;

                return true;
            }

            std::cout << "Enemy left with: " << enemyPlayerData.health << " health and "
                      << enemyPlayerData.armor << " armor" << std::endl;
        }

    } else {
        enemyPlayerData.health -= _damagePerRound;

        if (enemyPlayerData.health <= 0) {
            std::cout << "Enemy left with: " << enemyPlayerData.health << " health and "
                      << enemyPlayerData.armor << " armor" << std::endl;

            return true;
        }

        std::cout << "Enemy left with: " << enemyPlayerData.health << " health and "
                  << enemyPlayerData.armor << " armor" << std::endl;

        return false;
    }

    return false;
}
