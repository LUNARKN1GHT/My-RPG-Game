#include "skill/Fireball.h"
#include "character/Character.h"
#include <iostream>

/**
 * @brief 获取技能名称
 *
 * @return 技能名称
 */
std::string Fireball::getName() const {
    return "Fireball";
}

/**
 * @brief 使用技能
 *
 * @param user 技能使用者
 * @param target 技能目标
 */
void Fireball::use(Character& user, Character& target) {
    std::cout << user.getName() << " casts Fireball!\n";
    target.takeDamage(user.getAttack() + 10); // TODO: 增加火球伤害计算逻辑
}