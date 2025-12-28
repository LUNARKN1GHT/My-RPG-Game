#ifndef SKILL_H
#define SKILL_H

#include <string>

class Character; // 前向声明，避免头文件循环依赖

/**
 * @brief 技能基类（抽象类
 */
class Skill {
protected:
    int currentCooldown_ = 0; // 技能当前冷却时间

public:
    // 析构函数，允许子类改写
    virtual ~Skill() = default;

    // 技能基本信息
    virtual std::string getName() const = 0;        // 获取技能名称
    virtual std::string getDescription() const = 0; // 获取技能信息

    // 资源与规则
    virtual int getManaCost() const = 0; // 技能蓝量消耗
    virtual int getCooldown() const = 0; // 技能冷却时间

    // 使用规则
    bool canUse(const Character& user) const;

    // 使用后的处理
    void onUse(Character& user);

    // 回合推进
    void tickCooldown();

    // 技能效果
    virtual void use(Character& user, Character& target) = 0;
};

#endif // SKILL_H