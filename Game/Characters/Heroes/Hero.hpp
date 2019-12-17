//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_HERO_HPP
#define LOOP_HERO_HPP

#include "Ability.hpp"
#include "../Attributes/Coords.hpp"
#include "../Attributes/Effects.hpp"
#include "../Attributes/Strategy.hpp"
#include "../Attributes/Stats.hpp"

class Hero : public Stats {
public:

    virtual void attack(const Hero&) = 0;
    bool collide(const Hero&);
    void setStrategy(Strategy&);

protected:
    Coords mCoords;
    Strategy* mStrategy;
    Effects mEffect;
    std::vector<Ability*> mAbility;
};


#endif //LOOP_HERO_HPP
