#include "Barbarian.h"

static int barbarianCounter = 0;

Barbarian::Barbarian(const VitalData& vData) {
    _vitalData = vData;
    _name = AMAZON_NAME;
}

void Barbarian::readSpellFromInput(SpellType spellType) {
    SpellData sData;
    if (spellType == SpellType::Weak) {
        std::cin >> sData.name >> sData.damage;
        _spells[0] = sData;
    } else if (spellType == SpellType::Strong) {
        std::cin >> sData.name >> sData.damage >> sData.manaCost;
        _spells[1] = sData;
    }
}

int Barbarian::castSpell() {
    if (this->_vitalData.currMana >= _spells[STRONGER_SPELL].manaCost) {

        std::cout << BARBARIAN_NAME << " casting " << _spells[STRONGER_SPELL].name 
        << " for " << _spells[STRONGER_SPELL].manaCost << " mana" << std::endl;

        _vitalData.currMana -= _spells[STRONGER_SPELL].manaCost;

        return this->_spells[1].damage;
    }

    std::cout << BARBARIAN_NAME << " casting " << _spells[WEAKER_SPELL].name 
    << " for " << _spells[WEAKER_SPELL].manaCost << " mana"  << std::endl;

    return this->_spells[0].damage;
}

void Barbarian::takeDamage(int damage) {
    barbarianCounter++;
    if (barbarianCounter == BARBARIAN_PASSIVE_ABILITY_COUNTER) {
        damage /= 2;
    }
    
    std::cout << BARBARIAN_NAME << " took " << damage << " damage and is left with " 
    << _vitalData.health - damage << " health" << std::endl;

    this-> _vitalData.health -= damage;
}

void Barbarian::regenerate() {
    if ((_vitalData.currMana + _vitalData.manaRegenRate) >= _vitalData.maxMana) {

        std::cout << BARBARIAN_NAME << " regained " << _vitalData.maxMana - _vitalData.currMana << " mana for up to "
        << this->_vitalData.maxMana << std::endl;

        this->_vitalData.currMana = this->_vitalData.maxMana;
    } else {
        std::cout << BARBARIAN_NAME << " regained " << _vitalData.manaRegenRate << " mana for up to "
        << _vitalData.currMana + _vitalData.manaRegenRate << std::endl;

        this->_vitalData.currMana += this->_vitalData.manaRegenRate;
    }
}

bool Barbarian::isDead() const {
    if (this->_vitalData.health <= 0) {
        return true;
    }

    return false;
}
