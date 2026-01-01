//
// Created by LEE32 on 2026/1/1.
//

#ifndef MY_RPG_GAME_INPUTHANDLER_H
#define MY_RPG_GAME_INPUTHANDLER_H

#include <cstddef>

class Character;

class InputHandler {
    public:
    static size_t selectSkill(const Character& player);  // 选择角色技能
};

#endif //MY_RPG_GAME_INPUTHANDLER_H