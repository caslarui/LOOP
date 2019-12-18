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
    virtual void attack(const Hero&) = 0;
    bool collide(const Hero&);
    const Coords &getMCoords() const;
    const Effects &getMEffect() const;
    void setStrategy(Strategy&);

public:
    Coords mCoords;
    Strategy* mStrategy;
    Effects mEffect;
    std::vector<Ability*> mAbility{2, nullptr};
};

#endif //LOOP_HERO_HPP
