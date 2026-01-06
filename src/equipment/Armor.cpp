//
// Created by LEE32 on 2026/1/6.
//

#include "../../include/equipment/Armor.h"

Armor::Armor(const EquipSlot slot, const StatModifier bonus_modifier_)
    : slot_(slot), bonus_modifier_(bonus_modifier_){
}

EquipSlot Armor::getSlot() const {
    return slot_;
}

StatModifier Armor::getBonusModifier() const {
    return bonus_modifier_;
}
