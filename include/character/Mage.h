#include "Character.h"

class Mage : public Character {
public:
    Mage(const std::string& name);           // 构造函数
    void attack(Character& target) override; // 重写攻击函数
};