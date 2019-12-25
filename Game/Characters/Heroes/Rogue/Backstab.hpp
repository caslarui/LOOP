//
// Created by caslarui on 18.12.2019.
//

#ifndef LOOP_BACKSTAB_HPP
#define LOOP_BACKSTAB_HPP


#include "../Ability.hpp"

class Backstab : public Ability{
public:
    explicit Backstab(Hero&);
    float hit(Hero&, int) override;
    void upgradeAbility() override;

private:
    float baseDmg;
    constexpr const static float baseDmgIncrease = 20.0f;
};


#endif //LOOP_BACKSTAB_HPP
