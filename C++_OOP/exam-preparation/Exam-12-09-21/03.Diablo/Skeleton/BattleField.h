#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <memory>
#include <vector>
#include <string>

#include "Hero.h"

class BattleField {
public:
    void createHeroes();

    void createSpells();

    void startBattle();

    void printWinner(const std::unique_ptr<Hero>& hero);

private:
    std::vector<std::unique_ptr<Hero>> _heroes;
};

#endif // !BATTLEFIELD_H
