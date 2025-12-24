#include "character/Character.h"

#include <iostream>

int main() {
    Character newCharacter("Freshman", 10, 11, 12, 13, 14, 15);
    std::cout << newCharacter.getName() << std::endl;
    std::cout << newCharacter.getAttack() << std::endl;
    std::cout << newCharacter.getMana() << std::endl;
    std::cout << newCharacter.getMaxMana() << std::endl;
    std::cout << newCharacter.getHealth() << std::endl;
    std::cout << newCharacter.getMaxHealth() << std::endl;
    std::cout << newCharacter.getDefense() << std::endl;
}