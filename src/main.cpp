#include "../include/battle/Battle.h"
#include "../include/character/Archer.h"
#include "../include/character/Character.h"
#include "../include/character/Mage.h"
#include "../include/character/Warrior.h"
#include "../include/skill/BasicAttack.h"
#include "../include/skill/Fireball.h"
#include "../include/skill/Skill.h"
#include "../include/core/DamageType.h"
#include "../include/input/InputHandler.h"

#include <iostream>
#include <memory>

int main() {
    std::cout << "=== Battle System Test ===\n";

    Character player("Hero", 20, 50, 50, 5, 10, 100, 100);

    Character goblin("Goblin", 10, 0, 0, 2, 0, 60, 60);
    Character orc("Orc", 15, 0, 0, 5, 0, 80, 80);

    player.addSkill(std::make_unique<BasicAttack>());
    player.addSkill(std::make_unique<Fireball>());

    goblin.addSkill(std::make_unique<BasicAttack>());
    orc.addSkill(std::make_unique<BasicAttack>());

    Battle battle(&player);
    battle.addEnemy(&goblin);
    battle.addEnemy(&orc);

    battle.run();
}
