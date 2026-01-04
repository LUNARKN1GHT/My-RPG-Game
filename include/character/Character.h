#ifndef CHARACTER_H
#define CHARACTER_H

#include "../include/core/DamageType.h"
#include "../include/core/Modifier.h"

#include <memory>
#include <string>
#include <vector>

class Skill; // 前向声明
class Item;

/**
 * @brief 游戏中的角色类
 */
class Character {
    std::string name_; // 角色名称
    int attack_; // 角色攻击力
    int mana_; // 角色蓝量
    int maxMana_; // 角色最大蓝量
    int health_; // 角色生命值
    int maxHealth_; // 角色最大生命值
    int physicalDefense_; // 角色物理抗性
    int magicalDefense_; // 角色法术抗性

    std::vector<std::unique_ptr<Skill> > skills_; // 技能列表

    std::vector<std::unique_ptr<Item> > items_; // 物品列表

    int& getStatRef(StatType type); // 获取属性修改接口

public:
    Character(std::string name, int attack, int mana, int maxMana, int physicalDefense, int magicalDefense, int health,
              int maxHealth); // 构造函数
    virtual ~Character(); // 析构函数

    void takeDamage(int damage, DamageType damageType); // 角色受到伤害

    // 技能相关接口
    void addSkill(std::unique_ptr<Skill> skill); // 增加技能
    void useSkill(size_t index, Character &target); // 使用技能
    void consumeMana(int manaCost); // 技能使用蓝量，消耗蓝量
    [[nodiscard]] Skill *getSkill(size_t index) const; // 获取角色技能列表中的技能
    [[nodiscard]] size_t getSkillCount() const; // 获取技能数量

    // 物品相关接口
    void addItem(std::unique_ptr<Item> item); // 角色列表中增加物品
    void useItem(size_t index, Character &target); // 向某个目标使用特定物品
    [[nodiscard]] size_t getItemCount() const; // 获取物品列表中的物品数量
    [[nodiscard]] const std::vector<std::unique_ptr<Item> > &getItems() const; // 获取物品列表中所有列表
    [[nodiscard]] Item &getItem(size_t index) const; // 获取物品列表中的物品

    // 对外接口类函数
    [[nodiscard]] std::string getName() const; // 获取角色名字
    [[nodiscard]] int getAttack() const; // 获取角色攻击力
    [[nodiscard]] int getMana() const; // 获取角色蓝量
    [[nodiscard]] int getMaxMana() const; // 获取角色最大蓝量
    [[nodiscard]] int getPhysicalDefense() const; // 获取角色物理抗性
    [[nodiscard]] int getMagicalDefense() const; // 获取角色魔法抗性
    [[nodiscard]] int getHealth() const; // 获取角色生命值
    [[nodiscard]] int getMaxHealth() const; // 获取角色最大生命值
    virtual void printBasicInformation(); // 打印角色基本相关信息
    virtual void printSkillsInformation(); // 打印角色技能相关信息
    [[nodiscard]] const std::vector<std::unique_ptr<Skill> > &getSkills() const; // 获取角色技能信息

    // 角色属性调整函数
    void heal(int healAmount); // 角色恢复生命值
    void applyModifier(const StatModifier& modifier);
};

#endif // CHARACTER_H
