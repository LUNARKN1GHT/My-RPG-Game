#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>

class Skill; // 前向声明

/**
 * @brief 游戏中的角色类
 */
class Character {
private:
    std::string name_; // 角色名称
    int attack_;       // 角色攻击力
    int mana_;         // 角色蓝量
    int maxMana_;      // 角色最大蓝量
    int defense_;      // 角色防御力
    int health_;       // 角色生命值
    int maxHealth_;    // 角色最大生命值

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
    Character(const std::string name, int attack, int mana, int maxMana, int defense, int health,
              int maxHealth); // 构造函数
    virtual ~Character();     // 析构函数

    virtual void attack(Character& target); // 对目标的攻虚构击函数
    void takeDamage(int damage);            // 角色受到伤害

    // 对外接口类函数
    const std::string getName() const; // 获取角色名字
    const int getAttack() const;       // 获取角色攻击力
    const int getMana() const;         // 获取角色蓝量
    const int getMaxMana() const;      // 获取角色最大蓝量
    const int getDefense() const;      // 获取角色防御力
    const int getHealth() const;       // 获取角色生命值
    const int getMaxHealth() const;    // 获取角色最大生命值
    virtual void printInformation();   // 打印角色相关信息
};

#endif // CHARACTER_H