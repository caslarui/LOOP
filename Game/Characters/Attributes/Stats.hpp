//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_STATS_HPP
#define LOOP_STATS_HPP


//#include "../Heroes/Hero.hpp"

//class Hero;

class Stats {
public:
    Stats();

protected:
    int mCurrentHp;
    int mMaxHp;
    int mXp;
    int mLvl;
    bool dead;

    void takeDmg(int);
    void setDead();
    bool isDead();
    void earnXP(int);
};


#endif //LOOP_STATS_HPP
