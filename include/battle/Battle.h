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
    Character *player_; // 玩家角色
    std::vector<Character *> enemyList_; // 敌人列表

    void playerTurn() const; // 玩家回合
    void enemyTurn() const; // 敌人回合
    bool allEnemiesDefeated() const; // 判断是否所有敌人都被消灭
    bool isBattleOver() const; // 判断战斗是否结束

protected:
    void printEnemyList() const; // 打印敌人列表

public:
    explicit Battle(Character *player); // 构造函数

    void addEnemy(Character *enemy); // 增加敌人列表

    void start() const; // 游戏启动

    void run() const; // 战斗主循环
};

#endif // BATTLE_H
