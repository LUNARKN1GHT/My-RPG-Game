#include "../include/character/Mage.h"

// 构造函数
Mage::Mage(const std::string& name) : Character(name, 10, 50, 50, 5, 30, 30) {
}

// 重写攻击函数
void Mage::attack(Character& target) {
    // TODO: 增加打印回报信息

    // 基础攻击
    Character::attack(target);

    // TODO: 法师攻击特殊逻辑
}