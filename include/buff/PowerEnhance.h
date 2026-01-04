//
// Created by LEE32 on 2026/1/4.
//

#ifndef MY_RPG_GAME_POWERENHANCE_H
#define MY_RPG_GAME_POWERENHANCE_H

#include "../include/buff/Buff.h"
#include "../include/core/EffectType.h"

class PowerEnhance : public Buff {
private:
    int bonusPower_; // 提升的效果量

public:
    explicit PowerEnhance(int bonus, int duration);
    [[nodiscard]] std::string getName() const override;

    [[nodiscard]] std::string getDescription() const override;

    [[nodiscard]] EffectType getBuffType() const override;

    void onApply(Character &target) override;
    void onTick(Character &target) override;
    void onRemove(Character &target) override;

    [[nodiscard]] bool canApplyTo(const Character &target) const override;
};


#endif //MY_RPG_GAME_POWERENHANCE_H
