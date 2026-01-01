//
// Created by LEE32 on 2026/1/1.
//

#ifndef MY_RPG_GAME_INPUTHANDLER_H
#define MY_RPG_GAME_INPUTHANDLER_H

#include <cstddef>
#include <vector>

class Character;

class InputHandler {
public:
    /**
     * @brief 玩家操作标签
     */
    enum class Action {
        UseSkill,
        UseItem
    };

    static Action selectAction();
    static size_t selectSkill(const Character &player); // 选择角色技能
    static size_t selectEnemy(const std::vector<Character *> &enemies); // 选择敌人
    static size_t selectItem(const Character &player); // 选择玩家物品
};

#endif //MY_RPG_GAME_INPUTHANDLER_H
