//
// Created by LEE32 on 2026/1/1.
//

#ifndef MY_RPG_GAME_HEALTHPOTION_H
#define MY_RPG_GAME_HEALTHPOTION_H

#include "../include/item/Item.h"

class HealthPotion : public Item {
private:
    int healAmount_; // 回复效果

public:
    explicit HealthPotion(int healAmount); // 构造函数

    void use(Character &target) override; // 使用物品
};


#endif //MY_RPG_GAME_HEALTHPOTION_H
