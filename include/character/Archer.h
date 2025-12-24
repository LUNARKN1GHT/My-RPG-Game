#include "Character.h"

class Archer : public Character {
public:
    Archer(const std::string& name);         // 构造函数
    void attack(Character& target) override; // 重写攻击函数
};