//
// Created by LEE32 on 2026/1/4.
//

#ifndef MY_RPG_GAME_MODIFIER_H
#define MY_RPG_GAME_MODIFIER_H

#pragma once

#include "StatModifier.h"
#include "ModifyMode.h"
#include "EffectType.h"

struct StatModifier {
    StatType stat; // 修改哪个属性
    ModifyMode mode; // 修改方式
    float value; // 修改数值
    EffectType effectType; // 正/负/中
};

#endif //MY_RPG_GAME_MODIFIER_H
