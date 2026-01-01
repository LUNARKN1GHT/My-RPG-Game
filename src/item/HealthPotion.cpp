//
// Created by LEE32 on 2026/1/1.
//

#include "../include/item/HealthPotion.h"
#include "../include/item/Item.h"
#include <iostream>

#include "character/Character.h"

/**
 * @brief 血瓶类的构造函数
 *
 * @param healAmount 血瓶回复血量的数值
 */
HealthPotion::HealthPotion(const int healAmount)
    : Item("Health Potion", "Restores health", Item::TargetType::self),
      healAmount_(healAmount) {
}

/**
 * @brief 血瓶使用目标
 *
 * @param target 血瓶使用目标
 */
void HealthPotion::use(Character &target) {
    std::cout << target.getName() << " use Health Potion and restores " << healAmount_ << " HP.\n";

    target.heal(healAmount_);
}
