//
// Created by LEE32 on 2026/1/1.
//

#include "../include/item/Item.h"
#include "../include/skill/Skill.h"
#include "../include/input/InputHandler.h"
#include "../include/character/Character.h"
#include <iostream>

/**
 * @brief 玩家选择技能窗口
 *
 * @param player 玩家所用的角色类
 * @return 玩家的输入选择
 */
size_t InputHandler::selectSkill(const Character &player) {
    std::cout << "\nChoose a skill:\n";

    for (size_t i = 0; i < player.getSkillCount(); i++) {
        const Skill *skill = player.getSkill(i);
        std::cout << i << ". " << skill->getName() << "(Mana: " << skill->getManaCost() << ", CD: " << skill->
                getCooldown() << ")\n";
    }

    size_t choice;
    std::cin >> choice;

    return choice;
}

/**
 * @brief 玩家选择敌人窗口
 *
 * @param enemies 敌人列表
 * @return 玩家选择的敌人
 */
size_t InputHandler::selectEnemy(const std::vector<Character *> &enemies) {
    std::cout << "\nChoose a target:\n";

    for (size_t i = 0; i < enemies.size(); i++) {
        std::cout << i << ". " << enemies[i]->getName() << "(HP: " << enemies[i]->getHealth() << ")\n";
    }

    size_t choice;
    std::cin >> choice;
    return choice;
}

/**
 *
 * @param player 玩家角色
 * @return 玩家选择的物品
 */
size_t InputHandler::selectItem(const Character &player) {
    std::cout << "\nChoose a item:\n";

    for (size_t i = 0; i < player.getItemCount(); i++) {
        std::cout << i << ". " << player.getItems()[i]->getName() << "\n";
    }

    size_t choice;
    std::cin >> choice;
    return choice;
}
