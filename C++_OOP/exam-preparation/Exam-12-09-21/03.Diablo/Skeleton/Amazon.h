#ifndef AMAZON_H
#define AMAZON_H

#include "Hero.h"
#include "Defines.h"

class Amazon : public Hero {
public:
    Amazon(const VitalData& vData); 

    void readSpellFromInput(SpellType spellType) override;

    int castSpell() override;

    void takeDamage(int damage) override;

    void regenerate() override;

    bool isDead() const override;


private:

};

#endif // !AMAZON_H
