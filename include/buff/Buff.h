//
// Created by LEE32 on 2026/1/4.
//

#ifndef MY_RPG_GAME_BUFF_H
#define MY_RPG_GAME_BUFF_H

#include <string>

class Character;

class Buff {
public:
    enum class BuffType {
        Positive, // 正向增益
        Negative // 负向增益
    };

private:
    int remainTime_ = 0;

public:
    virtual ~Buff() = default;

    [[nodiscard]] virtual std::string getName() const = 0; // 获取效果名称
    [[nodiscard]] virtual std::string getDescription() const = 0; // 获取效果说明
    [[nodiscard]] virtual bool canApplyTo(const Character &target) const; // 生效规则
    [[nodiscard]] virtual BuffType getBuffType() const; // 获取技能效果
    virtual bool onApply(Character &target); // 刚被加上的效果
    virtual void onTick(Character &target); // 每个回合的效果
    virtual void onRemove(Character &target); // 被移除时的效果
    [[nodiscard]] int getRemainTime(); // 获取效果剩余作用时间
    [[nodiscard]] bool isExpired() const; // 判断技能效果是否过时
    void tickRemainTime(); // 回合推进
    void setRemainTime(); // 设置剩余时间
};


#endif //MY_RPG_GAME_BUFF_H
