#include "../include/character/Warrior.h"

// 构造函数
Warrior::Warrior(const std::string& name) : Character(name, 15, 20, 20, 15, 50, 50) {
}

// 攻击函数
void Warrior::attack(Character& target) {
    // TODO：增加打印回报信息
    // 基础攻击
    Character::attack(target);

    // 战士额外伤害
    target.takeDamage(5);
}