#include "BattleField.h"

#include "Amazon.cpp"
#include "Barbarian.cpp"
#include "BattleField.cpp"

int main()
{
    BattleField battleField;

    battleField.createHeroes();
    battleField.createSpells();
    battleField.startBattle();

    return EXIT_SUCCESS;
}
