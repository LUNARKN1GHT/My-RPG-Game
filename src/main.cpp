#include "../include/battle/Battle.h"
#include "../include/character/Archer.h"
#include "../include/character/Character.h"
#include "../include/character/Mage.h"
#include "../include/character/Warrior.h"

#include <iostream>

int main() {
    Warrior warrior01("Conan");
    Warrior warrior02("Gandalf");

    Battle battle(&warrior01);
    battle.addEnemy(&warrior02);

    battle.start();
}