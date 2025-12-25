#include "../include/character/Archer.h"
#include <iostream>
// 构造函数
Archer::Archer(const std::string& name) : Character(name, 10, 20, 20, 10, 40, 40) {
}

// 重写攻击函数
void Archer::attack(Character& target) {
    // 增加打印回报信息
    std::cout << getName() << " draws a bow...\n";

    // 基础攻击
    Character::attack(target);

    std::cout << getName() << "fires a precise arrow!\n";

        // 打印剩余生命值
    std::cout << target.getName() << " HP: " << target.getHealth() << "/" << target.getMaxHealth()
              << std::endl;
    // TODO：弓箭手特殊攻击逻辑
}