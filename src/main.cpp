#include "../include/battle/Battle.h"
#include "../include/character/Archer.h"
#include "../include/character/Character.h"
#include "../include/character/Mage.h"
#include "../include/character/Warrior.h"
#include "../include/skill/Fireball.h"

#include <iostream>
#include <memory>

int main() {
    Mage mage("Gandalf");
    Warrior enemy("orc");

    mage.addSkill(std::make_unique<Fireball>());
    mage.useSkill(0, enemy);

    mage.printInformation();
}