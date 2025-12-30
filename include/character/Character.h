#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include <string>
#include <vector>

class Skill; // 前向声明

/**
 * @brief 游戏中的角色类
 */
class Character {
    std::string name_; // 角色名称
    int attack_;       // 角色攻击力
    int mana_;         // 角色蓝量
    int maxMana_;      // 角色最大蓝量
    int defense_;      // 角色防御力
    int health_;       // 角色生命值
    int maxHealth_;    // 角色最大生命值

    std::vector<std::unique_ptr<Skill>> skills_; // 技能列表

public:
    /**
     * @brief 默认构造函数
     *
     * @param name 角色名称
     * @param attack 角色攻击力
     * @param mana 角色蓝量
     * @param maxMana 角色最大蓝量
     * @param defense 角色防御力
     * @param health 角色生命值
     * @param maxHealth 角色最大生命值
     */
    Character(std::string name, int attack, int mana, int maxMana, int defense, int health,
              int maxHealth); // 构造函数
    virtual ~Character();     // 析构函数

    void takeDamage(int damage); // 角色受到伤害

    // 技能相关接口
    void addSkill(std::unique_ptr<Skill> skill);    // 增加技能
    void useSkill(size_t index, Character& target); // 使用技能
    void consumeMana(int manaCost);                 // 技能使用蓝量，消耗蓝量
    [[nodiscard]] Skill* getSkill(size_t index) const;            // 获取角色技能列表中的技能
    [[nodiscard]] size_t getSkillCount() const;                   // 获取技能数量

    // 对外接口类函数
    [[nodiscard]] std::string getName() const;                           // 获取角色名字
    [[nodiscard]] int getAttack() const;                                 // 获取角色攻击力
    [[nodiscard]] int getMana() const;                                   // 获取角色蓝量
    [[nodiscard]] int getMaxMana() const;                                // 获取角色最大蓝量
    [[nodiscard]] int getDefense() const;                                // 获取角色防御力
    [[nodiscard]] int getHealth() const;                                 // 获取角色生命值
    [[nodiscard]] int getMaxHealth() const;                              // 获取角色最大生命值
    virtual void printInformation();                             // 打印角色相关信息
    [[nodiscard]] const std::vector<std::unique_ptr<Skill>> getSkills() const; // 获取角色技能信息
};

#endif // CHARACTER_H