//
// Created by caslarui on 18.12.2019.
//

#ifndef LOOP_EXECUTE_HPP
#define LOOP_EXECUTE_HPP


#include "../Ability.hpp"

class Execute : public Ability {
public:
    Execute();
    void hit(Hero&) override;
    void upgradeAbility() override;

private:
    float baseDmg;
    float hpLimit;
    constexpr static const float baseDmgIncrease = 30.0f;
    constexpr static const float hpLimitIncrease = 0.01f;
};


#endif //LOOP_EXECUTE_HPP
