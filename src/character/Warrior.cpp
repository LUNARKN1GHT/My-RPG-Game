#include "../include/character/Warrior.h"
#include "../include/skill/BasicAttack.h"

// 构造函数
Warrior::Warrior(const std::string &name) : Character(name, 15, 20, 20, 15, 50, 50) {
    addSkill(std::make_unique<BasicAttack>());
}
