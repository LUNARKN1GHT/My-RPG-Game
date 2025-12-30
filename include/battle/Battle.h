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
    Character *player_; // 玩家角色
    std::vector<Character *> enemyList_; // 敌人列表

protected:
    void printEnemyList() const; // 打印敌人列表

public:
    /**
     * @brief 构造函数
     *
     * @param player 进入战斗的角色
     */
    explicit Battle(Character *player); // 构造函数

    /**
     * @brief 在战斗中增加敌人
     *
     * @param enemy 加入战斗的敌人
     */
    void addEnemy(Character *enemy); // 增加敌人列表

    void start() const; // 游戏启动
};

#endif // BATTLE_H
