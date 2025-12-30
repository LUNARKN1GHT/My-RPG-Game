#include "../include/battle/Battle.h"
#include <iostream>

// 构造函数
Battle::Battle(Character* player) : player_(player) {
}

// 添加敌人
void Battle::addEnemy(Character* enemy) {
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

    Character* enemy = enemyList_[0];

    std::cout << "Battle Start!\n";

    // TODO: 增加 AI 攻击逻辑

    player_->useSkill(0, *enemy);
}
