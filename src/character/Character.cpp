#include "../include/character/Character.h"
#include "../include/skill/Skill.h"

#include <iostream>
#include <utility>

/**
     * @brief 默认构造函数
     *
     * @param name 角色名称
     * @param attack 角色攻击力
     * @param mana 角色蓝量
     * @param maxMana 角色最大蓝量
     * @param physicalDefense 角色物理抗性
     * @param magicalDefense 角色魔法抗性
     * @param health 角色生命值
     * @param maxHealth 角色最大生命值
     */
Character::Character(std::string name, const int attack, const int mana, const int maxMana,
                     const int physicalDefense, const int magicalDefense,
                     const int health, const int maxHealth) : name_(std::move(name)), attack_(attack), mana_(mana),
                                                              maxMana_(maxMana), health_(health),
                                                              maxHealth_(maxHealth),
                                                              physicalDefense_(physicalDefense),
                                                              magicalDefense_(magicalDefense) {
}

// 析构函数
Character::~Character() = default;

void Character::takeDamage(const int damage, DamageType damageType) {
    int defense = 0;

    switch (damageType) {
        case DamageType::Physical:
            defense = physicalDefense_;
            break;
        case DamageType::Magical:
            defense = magicalDefense_;
            break;
        case DamageType::TrueDamage:
            defense = 0;
    }

    int finalDamage = damage - defense;
    if (finalDamage < 0) {
        finalDamage = 0;
    }

    health_ -= finalDamage;
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
 * @param index 需要使用技能序号
 * @param target 技能使用目标
 */
void Character::useSkill(const size_t index, Character &target) {
    Skill *skill = getSkill(index);
    if (skill == nullptr) {
        std::cout << "Invalid skill index.\n";
        return;
    }

    if (!skill->canUse(*this)) {
        std::cout << "Cannot use skill: " << skill->getName() << "\n";
    }

    skill->use(*this, target);
    skill->onUse(*this);
}

// 获取角色名称
std::string Character::getName() const {
    return name_;
}

// 获取角色攻击力
int Character::getAttack() const {
    return attack_;
}

// 获取角色蓝量
int Character::getMana() const {
    return mana_;
}

// 获取角色最大蓝量
int Character::getMaxMana() const {
    return maxMana_;
}

// 获取角色物理抗性
int Character::getPhysicalDefense() const {
    return physicalDefense_;
}

// 获取角色魔法抗性
int Character::getMagicalDefense() const {
    return magicalDefense_;
}

// 获取角色生命值
int Character::getHealth() const {
    return health_;
}

// 获取角色最大生命值
int Character::getMaxHealth() const {
    return maxHealth_;
}

// 打印角色相关信息
void Character::printBasicInformation() {
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Attack: " << attack_ << std::endl;
    std::cout << "Physical defense: " << physicalDefense_ << std::endl;
    std::cout << "Magical defense: " << magicalDefense_ << std::endl;
    std::cout << "Mana: " << mana_ << "/" << maxMana_ << std::endl;
    std::cout << "Health: " << health_ << "/" << maxHealth_ << std::endl;
}

// 打印角色技能信息
void Character::printSkillsInformation() {
    std::cout << "\nSkills: " << std::endl;
    for (const auto &skill: skills_) {
        std::cout << skill->getName();
        switch (skill->getDamageType()) {
            case DamageType::Physical:
                std::cout << " (Physical) ";
                break;
            case DamageType::Magical:
                std::cout << " (Magical) ";
                break;
            case DamageType::TrueDamage:
                std::cout << " (TrueDamage) ";
                break;
        }
        std::cout << " : " << skill->getDescription() << std::endl;
    }
}

/**
 * @brief 获取角色技能列表中的技能
 *
 * @param index 技能列表中的技能序号
 *
 * @return 返回序号对应的技能
 */
Skill *Character::getSkill(const size_t index) const {
    if (index >= skills_.size()) {
        return nullptr;
    }
    return skills_[index].get();
}

/**
 * @brief 获取角色技能数量
 *
 * @return 角色技能数量
 */
size_t Character::getSkillCount() const {
    return skills_.size();
}

/**
 * @brief 角色消耗蓝量
 */
void Character::consumeMana(const int manaCost) {
    if (mana_ < manaCost) {
        mana_ = 0;
    } else {
        mana_ -= manaCost;
    }
}

// 获取角色全部技能组
const std::vector<std::unique_ptr<Skill> > &Character::getSkills() const {
    return this->skills_;
}
