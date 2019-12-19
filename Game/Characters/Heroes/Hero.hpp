//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_HERO_HPP
#define LOOP_HERO_HPP

#include <vector>
#include <ostream>

#include "Ability.hpp"
#include "../Attributes/Coords.hpp"
#include "../Attributes/Effects.hpp"
#include "../Attributes/Strategy.hpp"
#include "../Attributes/Stats.hpp"

class Hero : public Stats {
public:
    Hero(int, int);
    virtual void attack(Hero&) = 0;
    bool collide(const Hero&);
    bool isDead() override;
    void setDead() override;
    const Coords &getMCoords() const;
//    const Effects &getMEffect() const;
    void setStrategy(Strategy&);

    Coords mCoords;
    Strategy* mStrategy;
    std::vector<Effects> mEffect;
    std::vector<Ability*> mAbility;
};

#endif //LOOP_HERO_HPP
