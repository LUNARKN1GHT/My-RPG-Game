#ifndef SKILL_H
#define SKILL_H

#include <string>

class Character; // 前向声明，避免头文件循环依赖

/**
 * @brief 技能基类（抽象类
 */
class Skill {
private:
    std::string name_; // 技能的名称

public:
    // 析构函数，允许子类改写
    virtual ~Skill() = default;

    // 接口函数，获取技能名称
    virtual std::string getName() const = 0;

    // 使用技能
    virtual void use(Character& user, Character& target) = 0;
};

#endif // SKILL_H