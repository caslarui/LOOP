//
// Created by caslarui on 22.12.2019.
//

#ifndef LOOP_DEFLECT_HPP
#define LOOP_DEFLECT_HPP


#include "../Ability.hpp"
#include "Wizard.hpp"

class Deflect : public Ability {
public:
    Deflect(Hero&);
    float hit(Hero &enemy, int round) override ;
    void upgradeAbility() override ;

private:
    float basePct;
    constexpr static float basePctIncrease = 0.02f;

};


#endif //LOOP_DEFLECT_HPP
