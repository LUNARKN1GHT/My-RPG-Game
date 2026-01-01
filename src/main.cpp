#include "../include/battle/Battle.h"
#include "../include/character/Archer.h"
#include "../include/character/Character.h"
#include "../include/character/Mage.h"
#include "../include/character/Warrior.h"
#include "../include/skill/BasicAttack.h"
#include "../include/skill/Fireball.h"
#include "../include/skill/Skill.h"
#include "../include/core/DamageType.h"

#include <iostream>
#include <memory>

int main() {
    std::cout << "=== Skill List Test ===\n";

    Mage player("Hero");
    Character enemy("Dummy", 0, 0, 0, 0, 0, 100, 100);

    Fireball fireball;
    player.addSkill(std::make_unique<Fireball>());

    player.printBasicInformation();
    player.printSkillsInformation();
}
