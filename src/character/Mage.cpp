#include "../include/character/Mage.h"
#include "../include/skill/BasicAttack.h"

// 构造函数
Mage::Mage(const std::string &name) : Character(name, 10, 50, 50, 30, 5, 30, 30) {
    addSkill(std::make_unique<BasicAttack>()); // 增加普通攻击
}
