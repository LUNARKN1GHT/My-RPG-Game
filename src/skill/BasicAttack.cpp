#include "../include/skill/BasicAttack.h"
#include "../include/character/Character.h"
#include <iostream>

std::string BasicAttack::getName() const {
    return "Basic Attack";
}

std::string BasicAttack::getDescription() const {
    return "A basic physical attack.";
}

int BasicAttack::getManaCost() const {
    return 0;
}

int BasicAttack::getCooldown() const {
    return 0;
}

void BasicAttack::use(Character &user, Character &target) {
    std::cout << user.getName() << " attacks " << target.getName() << " with a basic attack!\n";

    target.takeDamage(user.getAttack());
}
