//
// Created by LEE32 on 2026/1/4.
//

#include "../../include/buff/Buff.h"
#include "../../include/buff/PowerEnhance.h"

PowerEnhance::PowerEnhance(const int bonus, const int duration)
    : bonusPower_(bonus), duration_(duration) {
}

std::string PowerEnhance::getName() const {
    return "Power Enhance";
}

std::string PowerEnhance::getDescription() const {
    return "Enhance character's power";
}

Buff::BuffType PowerEnhance::getBuffType() const {
    return BuffType::Positive;
}
