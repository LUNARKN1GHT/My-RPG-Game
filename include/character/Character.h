#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>

class Skill; // 前向声明

class Character {
private:
    std::string name_; // 角色名称
    int attack_;       // 角色攻击力
    int mana_;         // 角色蓝量
    int maxMana_;      // 角色最大蓝量
    int defense_;      // 角色防御力
    int maxHealth_;    // 角色最大生命值

protected:
    int health_; // 角色生命值

public:
    Character(const std::string name, int attack, int mana, int maxMana, int defense, int health,
              int maxHealth); // 构造函数
    virtual ~Character();     // 析构函数

    void takeDamage(int damage); // 角色受到伤害

    // 对外接口类函数
    const std::string getName() const; // 获取角色名字
    const int getAttack() const;       // 获取角色攻击力
    const int getMana() const;         // 获取角色蓝量
    const int getMaxMana() const;      // 获取角色最大蓝量
    const int getDefense() const;      // 获取角色防御力
    const int getHealth() const;       // 获取角色生命值
    const int getMaxHealth() const;    // 获取角色最大生命值
};

#endif // CHARACTER_H