//
// Created by caslarui on 17.12.2019.
//

#include "Stats.hpp"

void Stats::takeDmg(int dmg) {
    mCurrentHp -= dmg;
    if (mCurrentHp <= 0) {
        mCurrentHp = 0;
    }
}

Stats::Stats() {
    mCurrentHp = mMaxHp = mLvl = mXp = 0;
    dead = false;
}

void Stats::setDead() {
    dead = true;
}

bool Stats::isDead() {
    return dead;
}

void Stats::earnXP(int _xp) {
    this->mXp += _xp;
}
