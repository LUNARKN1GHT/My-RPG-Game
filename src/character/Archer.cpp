#include "../include/character/Archer.h"
#include "../include/skill/BasicAttack.h"

// 构造函数
Archer::Archer(const std::string& name) : Character(name, 10, 20, 20, 10, 40, 40) {
    addSkill(std::make_unique<BasicAttack>());
}