//
// Created by caslarui on 18.12.2019.
//

#ifndef LOOP_FIREBLAST_HPP
#define LOOP_FIREBLAST_HPP


#include "../Ability.hpp"

class Fireblast : public Ability {
public:
    explicit Fireblast(Hero&);

    float hit(Hero&, int) override;
    float getBaseDmg(Hero &, int) override ;
    void upgradeAbility() override;


private:
    float baseDmg;
    constexpr const static float baseDmgIncrease = 50.0f;
};


#endif //LOOP_FIREBLAST_HPP
