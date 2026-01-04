//
// Created by LEE32 on 2026/1/4.
//

#include "../../include/buff/Buff.h"
#include "../../include/buff/PowerEnhance.h"
#include "../../include/core/EffectType.h"
#include "../../include/core/Modifier.h"
#include "../../include/character/Character.h"

PowerEnhance::PowerEnhance(const int bonus, const int duration)
    : bonusPower_(bonus), duration_(duration) {
}

std::string PowerEnhance::getName() const {
    return "Power Enhance";
}

std::string PowerEnhance::getDescription() const {
    return "Enhance character's power";
}

EffectType PowerEnhance::getBuffType() const {
    return EffectType::Positive;
}

void PowerEnhance::onApply(Character &target) {
    const StatModifier modifier(StatType::Attack, ModifyMode::Add, bonusPower_, EffectType::Positive);
    target.applyModifier(modifier);
}

void PowerEnhance::onTick(Character &target) {

}

void PowerEnhance::onRemove(Character &target) {
    const StatModifier modifier(StatType::Attack, ModifyMode::Add, -bonusPower_, EffectType::Neutral);
    target.applyModifier(modifier);
}
