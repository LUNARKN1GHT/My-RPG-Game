#ifndef FIREBALL_H
#define FIREBALL_H

#include "../include/skill/Skill.h"

/**
 * @brief 技能：火球，继承自 SKill
 */
class Fireball : public Skill {
public:
    // 技能信息获取
    [[nodiscard]] std::string getName() const override; // 获取技能名称
    [[nodiscard]] std::string getDescription() const override; // 获取技能说明

    // 技能资源消耗
    [[nodiscard]] int getManaCost() const override; // 获取技能蓝量消耗
    [[nodiscard]] int getCooldown() const override; // 获取技能冷却时间

    // 角色使用技能
    void use(Character& user, Character& target) override;
};

#endif // FIREBALL_H