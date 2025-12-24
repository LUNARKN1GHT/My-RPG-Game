#include "character/Character.h"

#include <iostream>

int main() {
    Character newCharacter("Freshman", 10, 10, 10, 2, 20, 20);
    newCharacter.takeDamage(5);
    std::cout << newCharacter.getHealth() << std::endl;
}