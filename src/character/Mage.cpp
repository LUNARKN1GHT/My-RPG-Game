#include "../include/character/Mage.h"

// 构造函数
Mage::Mage(const std::string& name) : Character(name, 10, 50, 50, 5, 30, 30) {
}

// 重写攻击函数
void Mage::attack(Character& target) {
    std::cout << getName() << " begins to chant a spell...\n";

    // 基础攻击
    Character::attack(target);

    // 法师攻击特殊逻辑
    std::cout << "A burst of arcane energy hits " << target.getName() << "!\n";

        // 打印剩余生命值
    std::cout << target.getName() << " HP: " << target.getHealth() << "/" << target.getMaxHealth()
              << std::endl;
}