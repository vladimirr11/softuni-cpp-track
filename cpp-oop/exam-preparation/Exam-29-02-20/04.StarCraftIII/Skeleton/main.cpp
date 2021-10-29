#include <iostream>
#include <string>

#include "BattleField.h"

#include "BattleField.cpp"
#include "AirShip.cpp"

#include "TerranAirShip.cpp"
#include "Viking.cpp"
#include "BattleCruser.cpp"

#include "ProtossAirShip.cpp"
#include "Phoenix.cpp"
#include "Carrier.cpp"

int main()
{
    std::string terranFleetComposition;
    std::string protossFleetCompositon;

    std::cin >> terranFleetComposition >> protossFleetCompositon;

    BattleField battleField;

    battleField.generateTerranFleet(terranFleetComposition);
    battleField.generateProtossFleet(protossFleetCompositon);

    battleField.startBattle();

    return 0;
}
