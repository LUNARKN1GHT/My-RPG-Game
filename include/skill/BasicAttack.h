#ifndef BASIC_ATTACK_H
#define BASIC_ATTACK_H

#include "skill/Skill.h"

/**
 * @brief 普通攻击，继承自技能类
 */
class BasicAttack : public Skill {
public:
    [[nodiscard]] std::string getName() const override;
    [[nodiscard]] std::string getDescription() const override;

    [[nodiscard]] int getManaCost() const override;
    [[nodiscard]] int getCooldown() const override;

    void use(Character& user, Character& target) override;
};

#endif // BASIC_ATTACK_H