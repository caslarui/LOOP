//
// Created by caslarui on 17.12.2019.
//

#include "Stats.hpp"

void Stats::takeDmg(int dmg) {
    mCurrentHp -= dmg;
    if (mCurrentHp <= 0) {
        mCurrentHp = 0;
        dead = true;
    }
}

Stats::Stats() {
    mCurrentHp = mMaxHp = mLvl = mXp = mHpInc = 0;
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
    int lvl = 0;
    while ( (250 + lvl * 50) <= mXp) {
        ++lvl;
    }
    if (lvl > mLvl) {
        mMaxHp += mHpInc * (lvl - mLvl);
        mLvl = lvl;
        mCurrentHp = mMaxHp;
    }
}
