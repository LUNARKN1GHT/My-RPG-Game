#include "../include/character/Warrior.h"
#include <iostream>

// 构造函数
Warrior::Warrior(const std::string& name) : Character(name, 15, 20, 20, 15, 50, 50) {
}

// 攻击函数
void Warrior::attack(Character& target) {
    std::cout << getName() << " raises his weapon and charges forward!\n";

    // 基础攻击
    Character::attack(target);

    // 战士额外伤害
    std::cout << getName() << " delivers a powerful follow-up strike!\n";
    target.takeDamage(5);

        // 打印剩余生命值
    std::cout << target.getName() << " HP: " << target.getHealth() << "/" << target.getMaxHealth()
              << std::endl;
}