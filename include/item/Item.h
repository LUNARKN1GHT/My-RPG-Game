//
// Created by LEE32 on 2026/1/1.
//

#ifndef MY_RPG_GAME_ITEM_H
#define MY_RPG_GAME_ITEM_H

#include <complex.h>
#include <string>

class Character;

class Item {
private:
    std::string name_;  // 物品名称
    std::string descriptions_;  // 物品描述

public:
    Item(std::string name, std::string description);    // 构造函数
    virtual ~Item() = default;  // 析构函数

    virtual void use(Character& target) = 0;    // 物品使用函数

    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] const std::string& getDescription() const;
};


#endif //MY_RPG_GAME_ITEM_H