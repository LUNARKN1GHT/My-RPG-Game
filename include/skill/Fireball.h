#ifndef FIREBALL_H
#define FIREBALL_H

#include "../include/skill/Skill.h"

/**
 * @brief 技能：火球，继承自 SKill
 */
class Fireball : public Skill {
public:
    [[nodiscard]] std::string getName() const override;
    [[nodiscard]] std::string getDescription() const override;

    [[nodiscard]] int getManaCost() const override;
    [[nodiscard]] int getCooldown() const override;

    void use(Character& user, Character& target) override;
};

#endif // FIREBALL_H