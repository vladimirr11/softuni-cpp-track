#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Hero.h"
#include "Defines.h"

class Barbarian : public Hero {
public:
    Barbarian(const VitalData& vData);

    void readSpellFromInput(SpellType spellType) override;

    int castSpell() override;

    void takeDamage(int damage) override;

    void regenerate() override;

    bool isDead() const override;

private:
};

#endif // !BARBARIAN_H
