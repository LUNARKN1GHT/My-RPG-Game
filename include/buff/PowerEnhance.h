//
// Created by LEE32 on 2026/1/4.
//

#ifndef MY_RPG_GAME_POWERENHANCE_H
#define MY_RPG_GAME_POWERENHANCE_H

#include "../include/buff/Buff.h"

class PowerEnhance : public Buff {
private:
    int bonusPower_; // 提升的效果量
    int duration_;  // 持续的时间

public:
    explicit PowerEnhance(int bonus, int duration);
    [[nodiscard]] std::string getName() const override;

    [[nodiscard]] std::string getDescription() const override;

    [[nodiscard]] BuffType getBuffType() const override;
};


#endif //MY_RPG_GAME_POWERENHANCE_H
