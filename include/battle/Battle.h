#ifndef BATTLE_H
#define BATTLE_H

#include "../include/character/Character.h"

#include <vector>

/**
 * @brief 战斗系统
 *
 * @date 2025-12-25
 * @note 暂时只支持双方对战的情况
 */
class Battle {
private:
    Character* player_;                 // 玩家角色
    std::vector<Character*> enemyList_; // 敌人列表

protected:
    void printEnemyList(); // 打印敌人列表

public:
    Battle(Character* player);       // 构造函数
    void addEnemy(Character* enemy); // 增加敌人列表

    void start(); // 游戏启动
};

#endif // BATTLE_H