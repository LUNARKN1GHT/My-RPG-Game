#include "../include/character/Archer.h"
#include "../include/character/Character.h"
#include "../include/character/Mage.h"
#include "../include/character/Warrior.h"

#include <iostream>

int main() {
    Character timber("Timber", 10, 10, 10, 2, 20, 20);
    Warrior warrior("Warrior_01");
    warrior.printInformation();
    std::cout << std::endl;
    timber.printInformation();
    std::cout << std::endl;

    warrior.attack(timber);
    timber.printInformation();
}