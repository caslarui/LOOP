//
// Created by caslarui on 18.12.2019.
//

#ifndef LOOP_IGNITE_HPP
#define LOOP_IGNITE_HPP


#include "../Ability.hpp"

class Ignite : public Ability {
public:
    Ignite();
    void hit(Hero&, int) override;
    void upgradeAbility() override;

private:
    float baseDmg;
    float effectDmg;
    constexpr static float baseDmgIncrease = 20.0f;
    constexpr static float effectDmgIncrease = 30.0f;
};


#endif //LOOP_IGNITE_HPP
