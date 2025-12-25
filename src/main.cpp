#include "../include/battle/Battle.h"
#include "../include/character/Archer.h"
#include "../include/character/Character.h"
#include "../include/character/Mage.h"
#include "../include/character/Warrior.h"

#include <iostream>

int main() {
    Warrior warrior("Conan");
    Mage mage("Gandalf");

    Battle battle(&warrior);
    battle.addEnemy(&mage);

    battle.start();
}