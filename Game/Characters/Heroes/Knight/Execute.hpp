//
// Created by caslarui on 18.12.2019.
//

#ifndef LOOP_EXECUTE_HPP
#define LOOP_EXECUTE_HPP


#include "../Ability.hpp"

class Execute : public Ability {
public:
    explicit Execute(Hero&);

    float hit(Hero& enemy, int round) override;
    void upgradeAbility() override;
    float getBaseDmg(Hero &, int) override ;

private:
    float baseDmg;
    float hpLimit;
    constexpr static const float baseDmgIncrease = 30.0f;
    constexpr static const float hpLimitIncrease = 0.01f;
};


#endif //LOOP_EXECUTE_HPP
