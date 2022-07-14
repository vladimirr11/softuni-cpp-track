#include "DesertEagle.h"

DesertEagle::DesertEagle(const int damagePerRound, const int clipSize,
                         const int remainingAmmo) : 
    Pistol(damagePerRound, clipSize, remainingAmmo) {}


bool DesertEagle::fire(PlayerVitalData &enemyPlayerData) {
    if (_currClipBullets == 0) {
        Pistol::reload();
        return false;
    }
    _currClipBullets--;

    const int DAMAGE_HEALTH = (_damagePerRound * 3) / 4;
    const int DAMAGE_ARMOR = (_damagePerRound) / 4;

    enemyPlayerData.armor -= DAMAGE_ARMOR;
    if (enemyPlayerData.armor <= 0) {
        enemyPlayerData.health += enemyPlayerData.armor;
        enemyPlayerData.armor = 0;
    }

    enemyPlayerData.health -= DAMAGE_HEALTH;

    std::cout << "Enemy left with: " << enemyPlayerData.health << " health and " << 
    enemyPlayerData.armor << " armor" << std::endl;

    if (enemyPlayerData.health <= 0) {
        return true;
    }

    return false;
}