//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_STATS_HPP
#define LOOP_STATS_HPP

class Stats {
public:
    Stats();

    void earnXP(int);
    void takeDmg(int);

    virtual void setDead();
    virtual bool isDead();

    int mCurrentHp;
    int mMaxHp;
    int mHpInc;
    int mXp;
    int mLvl;
    bool dead;
};


#endif //LOOP_STATS_HPP
