#include "Archer.h"

// 构造函数
Archer::Archer(const std::string& name) : Character(name, 10, 20, 20, 10, 40, 40) {
}

// 重写攻击函数
void Archer::attack(Character& target) {
    // 增加打印回报信息

    // 基础攻击
    Character::attack(target);

    // TODO：弓箭手特殊攻击逻辑
}