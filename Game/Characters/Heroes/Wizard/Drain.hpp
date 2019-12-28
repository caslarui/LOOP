//
// Created by caslarui on 18.12.2019.
//

#ifndef LOOP_DRAIN_HPP
#define LOOP_DRAIN_HPP


#include "../Ability.hpp"

class Drain : public Ability {
public:
    explicit Drain(Hero&);
    float hit(Hero &enemy, int round) override ;
    void upgradeAbility() override ;
    float getBaseDmg(Hero &, int) override ;


private:
    float basePct;
    constexpr static float basePctIncrease = 0.05f;
};


#endif //LOOP_DRAIN_HPP
