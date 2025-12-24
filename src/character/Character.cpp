#include "character/Character.h"

/**
 * @brief 构造一个角色
 * @param name 角色名称
 * @param attack 角色攻击力
 * @param mana 角色蓝量
 * @param maxMana 角色最大蓝量
 * @param defense 角色防御力
 * @param health 角色生命值
 * @param maxHealth 角色最大生命值
 */
Character::Character(const std::string name, int attack, int mana, int maxMana, int defense,
                     int health, int maxHealth) :
    name_(name), attack_(attack), mana_(mana), maxMana_(maxMana), defense_(defense),
    health_(health), maxHealth_(maxHealth) {
}

// 析构函数
Character::~Character() {
}

// 获取角色名称
const std::string Character::getName() const {
    return name_;
}

// 获取角色攻击力
const int Character::getAttack() const {
    return attack_;
}

// 获取角色蓝量
const int Character::getMana() const {
    return mana_;
}

// 获取角色最大蓝量
const int Character::getMaxMana() const {
    return maxMana_;
}

// 获取角色防御力
const int Character::getDefense() const {
    return defense_;
}

// 获取角色生命值
const int Character::getHealth() const {
    return health_;
}

// 获取角色最大生命值
const int Character::getMaxHealth() const {
    return maxHealth_;
}