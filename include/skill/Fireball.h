#ifndef FIREBALL_H
#define FIREBALL_H

#include "../include/skill/Skill.h"

/**
 * @brief 技能：火球，继承自 SKill
 */
class Fireball : public Skill {
public:
    std::string getName() const override;
    void use(Character& user, Character& target) override;
    std::string getDescription() const override;
};

#endif // FIREBALL_H