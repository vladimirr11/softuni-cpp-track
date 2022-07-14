#include "Amazon.h"

static int counter = 0;

Amazon::Amazon(const VitalData& vData) {
    _vitalData = vData;
    _name = AMAZON_NAME;
}

void Amazon::readSpellFromInput(SpellType spellType) {
    SpellData sData;
    if (spellType == SpellType::Weak) {
        std::cin >> sData.name >> sData.damage;
        _spells[0] = sData;
    } else if (spellType == SpellType::Strong) {
        std::cin >> sData.name >> sData.damage >> sData.manaCost;
        _spells[1] = sData;
    }
}

int Amazon::castSpell() {
    counter++;
    if (this->_vitalData.currMana >= _spells[STRONGER_SPELL].manaCost) {
        if (counter % 2 == 0) {
            std::cout << AMAZON_NAME << " casting " << _spells[STRONGER_SPELL].name 
            << " for " << _spells[STRONGER_SPELL].manaCost << " mana" << std::endl;

            _vitalData.currMana -= _spells[STRONGER_SPELL].manaCost;

            return this->_spells[STRONGER_SPELL].damage * 1.25;
        }

        std::cout << AMAZON_NAME << " casting " << _spells[STRONGER_SPELL].name 
        << " for " << _spells[STRONGER_SPELL].manaCost << " mana" << std::endl;

        _vitalData.currMana -= _spells[STRONGER_SPELL].manaCost;

        return this->_spells[STRONGER_SPELL].damage;
    }

    if (counter % 2 == 0) {
        std::cout << AMAZON_NAME << " casting " << _spells[WEAKER_SPELL].name 
        << " for " << _spells[WEAKER_SPELL].manaCost << " mana" << std::endl;

        return this->_spells[WEAKER_SPELL].damage * 1.25;
    }

    std::cout << AMAZON_NAME << " casting " << _spells[WEAKER_SPELL].name 
    << " for " << _spells[WEAKER_SPELL].manaCost << " mana" << std::endl;

    return this->_spells[WEAKER_SPELL].damage;
}

void Amazon::takeDamage(int damage) {
    std::cout << AMAZON_NAME << " took " << damage << " damage and is left with " 
    << _vitalData.health - damage << " health" << std::endl;

    this-> _vitalData.health -= damage;
}

void Amazon::regenerate() {
    if ((this->_vitalData.currMana + this->_vitalData.manaRegenRate) > this->_vitalData.maxMana) {

        std::cout << AMAZON_NAME << " regained " << _vitalData.maxMana - _vitalData.currMana << " mana for up to "
        << this->_vitalData.maxMana << std::endl;

        this->_vitalData.currMana = this->_vitalData.maxMana;
    } else {
        std::cout << AMAZON_NAME << " regained " << _vitalData.manaRegenRate << " mana for up to "
        << _vitalData.currMana + _vitalData.manaRegenRate << std::endl;

        this->_vitalData.currMana += this->_vitalData.manaRegenRate;
    }
}

bool Amazon::isDead() const {
    if (this->_vitalData.health <= 0) {
        return true;
    }

    return false;
}
