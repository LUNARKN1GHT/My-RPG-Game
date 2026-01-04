//
// Created by LEE32 on 2026/1/4.
//

#include "../../include/buff/Buff.h"

int Buff::getRemainTime() const {
    return remainTime_;
}

bool Buff::isExpired() const {
    return remainTime_ == 0;
}

void Buff::tickRemainTime() {
    if (remainTime_ > 0) {
        --remainTime_;
    }
}

void Buff::setRemainTime(const int time) {
    remainTime_ = time < 0 ? 0 : time;
}
