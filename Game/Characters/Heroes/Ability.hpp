//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_ABILITY_HPP
#define LOOP_ABILITY_HPP


//#include "Hero.hpp"
class Hero;

class Ability {
public:

    explicit Ability(Hero &owner) : mOwner(&owner){};

    virtual float hit(Hero & enemy, int round) = 0;
    virtual void upgradeAbility() = 0;
    virtual float getBaseDmg(Hero &, int) = 0;

    Hero* mOwner = nullptr;
};


#endif //LOOP_ABILITY_HPP
