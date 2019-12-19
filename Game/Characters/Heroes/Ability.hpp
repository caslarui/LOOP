//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_ABILITY_HPP
#define LOOP_ABILITY_HPP


//#include "Hero.hpp"
class Hero;

class Ability {
public:

    virtual void hit(Hero &) = 0;
    virtual void upgradeAbility() = 0;

    Hero* mOwner = nullptr;
};


#endif //LOOP_ABILITY_HPP
