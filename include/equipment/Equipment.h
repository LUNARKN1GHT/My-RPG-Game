//
// Created by LEE32 on 2026/1/5.
//

#ifndef MY_RPG_GAME_EQUIPMENT_H
#define MY_RPG_GAME_EQUIPMENT_H

#include "../core//EquipSlot.h"

#include <string>

class Equipment {
public:
    virtual ~Equipment() = default;

    virtual std::string getName() const = 0; // 获取装备名称
    virtual EquipSlot getSlot() const = 0; // 获取装备类型
};

#endif //MY_RPG_GAME_EQUIPMENT_H