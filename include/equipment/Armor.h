//
// Created by LEE32 on 2026/1/6.
//

#ifndef MY_RPG_GAME_ARMOR_H
#define MY_RPG_GAME_ARMOR_H

#include "../include/equipment/Equipment.h"
#include "../include/core/EquipSlot.h"

class Armor : public Equipment {
protected:
    EquipSlot slot_;
    StatModifier bonus_modifier_;

public:
    Armor(EquipSlot slot, StatModifier bonus_modifier_);

    [[nodiscard]] EquipSlot getSlot() const override;

    [[nodiscard]] StatModifier getBonusModifier() const override;
};

class IronHelmet : public Armor {
public:
    IronHelmet() : Armor(
        EquipSlot::Helmet,
        StatModifier(StatType::MagicalDefense, ModifyMode::Add, 5, EffectType::Positive)
        ) {}

    std::string getName() const override {
        return "Iron Helmet";
    }
};


#endif //MY_RPG_GAME_ARMOR_H
