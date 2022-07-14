#include "Glock.h"

#include <math.h>
#include <iostream>

const int NUM_BULETS = 3;

Glock::Glock(const int damagePerRound,
             const int clipSize,
             const int remainingAmmo) : Pistol(damagePerRound, clipSize, remainingAmmo) {}

bool Glock::fire(PlayerVitalData &enemyPlayerData) {
    for (int i = 0; i < NUM_BULETS; i++) {
        if (_currClipBullets == 0) {
            Pistol::reload();
            return false;
        }

        _currClipBullets--;

        if (enemyPlayerData.armor) {
            enemyPlayerData.armor -= (_damagePerRound / 2);
            enemyPlayerData.health -= (_damagePerRound / 2);

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
        }

    }

    return false;
}
