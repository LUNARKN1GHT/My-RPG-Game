#include "../include/skill/Skill.h"
#include "../include/character/Character.h"

bool Skill::canUse(const Character &user) const {
    return user.getMana() >= getManaCost() && currentCooldown_ == 0;
}

/**
 * @brief 技能使用逻辑
 *
 * @param user 技能使用者
 */
void Skill::onUse(Character &user) {
    user.consumeMana(getManaCost());
    currentCooldown_ = getCooldown();
}

/**
 * @brief 技能冷却计数
 */
void Skill::tickCooldown() {
    if (currentCooldown_ > 0) {
        --currentCooldown_;
    }
}
