//
// Created by caslarui on 22.12.2019.
//

#ifndef LOOP_DEFLECT_HPP
#define LOOP_DEFLECT_HPP


#include "../Ability.hpp"

class Deflect : public Ability {
public:
    explicit Deflect(Hero&);
    float hit(Hero &enemy, int round) override ;
    void upgradeAbility() override ;
    float getBaseDmg(Hero &, int) override ;

private:
    float basePct;
    constexpr static float basePctIncrease = 0.02f;

};


#endif //LOOP_DEFLECT_HPP
