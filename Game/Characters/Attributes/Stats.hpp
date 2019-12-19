//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_STATS_HPP
#define LOOP_STATS_HPP

class Stats {
public:
    Stats();

    void takeDmg(int);

    virtual void setDead();

    virtual bool isDead();
    void earnXP(int);

    int mCurrentHp;
    int mMaxHp;
    int mXp;
    int mLvl;
    bool dead;
};


#endif //LOOP_STATS_HPP
