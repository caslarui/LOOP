//
// Created by caslarui on 18.12.2019.
//

#ifndef LOOP_PARALYSIS_HPP
#define LOOP_PARALYSIS_HPP


#include "../Ability.hpp"

class Paralysis: public Ability {
public:
    explicit Paralysis(Hero&);
    float hit(Hero&, int) override;
    void upgradeAbility() override;

private:
    float baseDmg;
    constexpr const static float baseDmgIncrease = 10.0f;
};


#endif //LOOP_PARALYSIS_HPP
