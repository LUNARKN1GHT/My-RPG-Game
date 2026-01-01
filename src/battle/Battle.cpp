#include "../include/battle/Battle.h"

#include <algorithm>

#include "../include/skill/Skill.h"
#include "../include/input/InputHandler.h"
#include <iostream>
#include <ranges>

/**
 * @brief 构造函数
 *
 * @param player 进入战斗的角色
 */
Battle::Battle(Character *player) : player_(player) {
}

/**
 * @brief 在战斗中增加敌人
 *
 * @param enemy 加入战斗的敌人
 */
void Battle::addEnemy(Character *enemy) {
    if (enemy) {
        enemyList_.push_back(enemy);
    }
}

// 打印敌人列表
void Battle::printEnemyList() const {
    // TODO: 打印敌人列表提示
    for (size_t i = 0; i < enemyList_.size(); ++i) {
        std::cout << i << ": " << enemyList_[i]->getName() << "(HP: " << enemyList_[i]->getHealth()
                << ")\n";
    }
}

// 战斗开始
void Battle::start() const {
    if (!player_ || enemyList_.empty()) {
        // 空指针检查，不存在角色或敌人的时候直接返回
        std::cout << "Battle cannot start.\n";
        return;
    }

    Character *enemy = enemyList_[0];

    std::cout << "Battle Start!\n";

    // TODO: 增加 AI 攻击逻辑

    player_->useSkill(0, *enemy);
}

/**
 * @brief 战斗系统
 */
void Battle::run() const {
    std::cout << "=== Battle Start! ===\n";

    while (!isBattleOver()) {
        playerTurn();
        if (isBattleOver()) break;

        enemyTurn();
        if (isBattleOver()) break;

        // 回合结束：冷却推进
        for (size_t i = 0; i < player_->getSkillCount(); i++) {
            player_->getSkill(i)->tickCooldown();
        }
    }

    if (player_->getHealth() > 0) {
        std::cout << "You win!\n";
    } else {
        std::cout << "You lost!\n";
    }
}

/**
 * @brief 处理玩家回合
 */
void Battle::playerTurn() const {
    std::cout << "\n--- Player Turn! ---\n";

    const size_t skillIndex = InputHandler::selectSkill(*player_);
    const size_t targetIndex = InputHandler::selectEnemy(enemyList_);

    player_->useSkill(skillIndex, *enemyList_[targetIndex]);
}

/**
 * @brief 处理敌人回合
 */
void Battle::enemyTurn() const {
    std::cout << "\n--- Enemy Turn! ---\n";

    // TODO：优化敌人战斗逻辑，这里暂时只是使用普攻
    for (const auto &enemy : enemyList_) {
        enemy->useSkill(0, *player_);

        if (player_->getHealth() <= 0) {
            break;
        }
    }
}

/**
 * @brief 判断是否所有敌人都被打败
 *
 * @return 敌人是否都被打败的 bool 值
 */
bool Battle::allEnemiesDefeated() const {
    return std::ranges::all_of(enemyList_, [](const Character* enemy) {
        return enemy->getHealth() <= 0;
    });
}

/**
 * @brief 判断战斗是否结束
 *
 * @return 战斗是否结束的 bool 值
 */
bool Battle::isBattleOver() const {
    return player_->getHealth() <= 0 || allEnemiesDefeated();
}

