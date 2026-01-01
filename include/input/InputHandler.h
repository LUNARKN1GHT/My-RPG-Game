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
    static size_t selectSkill(const Character &player); // 选择角色技能
    static size_t selectEnemy(const std::vector<Character *> &enemies); // 选择敌人
};

#endif //MY_RPG_GAME_INPUTHANDLER_H
