#include "../include/character/Character.h"
#include "../include/skill/Skill.h"

#include <iostream>

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

// 攻击目标函数
void Character::attack(Character& target) {
    // 打印攻击前信息
    std::cout << getName() << " attacks " << target.getName() << "!\n";

    // 具体攻击实现
    target.takeDamage(attack_);

    // TODO: 增加游戏终止逻辑
}

void Character::takeDamage(int damage) {
    // TODO: 这里暂时用简单伤害计算系统，后续可以调整
    // TODO：增加打印回报信息
    if (damage < defense_) {
        // 如果伤害小于护盾值，则不扣血
        return;
    } else {
        // 简单地用伤害值减去防御力
        health_ -= damage - defense_;
    }
}

/**
 * @brief 增加角色技能
 *
 * @param skill 增加的技能
 */
void Character::addSkill(std::unique_ptr<Skill> skill) {
    skills_.push_back(std::move(skill));
}

/**
 * @brief 使用技能
 *
 * @param index 使用技能的序号
 * @param target 技能使用目标
 */
void Character::useSkill(size_t index, Character& target) {
    if (index >= skills_.size()) {
        std::cout << "Invalid skill index!\n";
        return;
    }

    std::cout << getName() << " uses " << skills_[index]->getName() << "!\n";

    skills_[index]->use(*this, target);
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

// 打印角色相关信息
void Character::printInformation() {
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Attack: " << attack_ << std::endl;
    std::cout << "Defense: " << defense_ << std::endl;
    std::cout << "Mana: " << mana_ << "/" << maxMana_ << std::endl;
    std::cout << "Health: " << health_ << "/" << maxHealth_ << std::endl;

    std::cout << "\nSkills: " << std::endl;
    // 打印角色技能列表
    for (size_t index = 0; index < skills_.size(); index++) {
        std::cout << skills_[index]->getName() << " : " << skills_[index]->getDescription()
                  << std::endl;
    }
}

/**
 * @brief 技能对角色蓝量的消耗
 *
 * @param manaCost 技能需要的蓝量
 */