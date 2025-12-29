#include "../include/battle/Battle.h"
#include "../include/character/Archer.h"
#include "../include/character/Character.h"
#include "../include/character/Mage.h"
#include "../include/character/Warrior.h"
#include "../include/skill/BasicAttack.h"
#include "../include/skill/Fireball.h"

#include <iostream>
#include <memory>

int main() {
    std::cout << "=== RPG Skill System Test ===\n\n";

    // 1️⃣ 创建角色
    Character player("Hero", 20, 50, 50, 5, 100, 100);
    Character enemy("Goblin", 10, 0, 0, 2, 60, 60);

    // 2️⃣ 给玩家添加技能
    player.addSkill(std::make_unique<BasicAttack>());
    player.addSkill(std::make_unique<Fireball>());

    // 3️⃣ 打印技能列表
    std::cout << "Player Skills:\n";
    for (size_t i = 0; i < player.getSkillCount(); ++i) {
        Skill* skill = player.getSkill(i);
        std::cout << i << ". " << skill->getName() << " | Mana: " << skill->getManaCost()
                  << " | Cooldown: " << skill->getCooldown() << "\n";
    }

    std::cout << "\n";

    // 4️⃣ 使用普通攻击
    std::cout << ">>> Player uses Basic Attack\n";
    player.useSkill(0, enemy);

    std::cout << "Enemy HP: " << enemy.getHealth() << "\n\n";

    // 5️⃣ 使用 Fireball
    std::cout << ">>> Player uses Fireball\n";
    player.useSkill(1, enemy);

    std::cout << "Enemy HP: " << enemy.getHealth() << "\n\n";

    // 6️⃣ 立刻再次使用 Fireball（应失败，冷却中）
    std::cout << ">>> Player tries Fireball again\n";
    player.useSkill(1, enemy);

    // 7️⃣ 推进回合（冷却减少）
    std::cout << "\n--- End of Turn ---\n";
    for (size_t i = 0; i < player.getSkillCount(); ++i) {
        player.getSkill(i)->tickCooldown();
    }

    // 8️⃣ 再试一次 Fireball
    std::cout << "\n>>> Player tries Fireball after cooldown tick\n";
    player.useSkill(1, enemy);

    std::cout << "\nEnemy HP: " << enemy.getHealth() << "\n";

    std::cout << "\n=== Test Finished ===\n";
    return 0;
}