#include "BattleField.h"

#include "Amazon.h"
#include "Barbarian.h"
#include "BattleField.h"

int main() {
    BattleField battleField;

    battleField.createHeroes();
    battleField.createSpells();

    battleField.startBattle();

    return EXIT_SUCCESS;
}
