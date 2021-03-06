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
#include "../Attributes/Stats.hpp"

class Hero : public Stats {
public:
    Hero(int, int);
    virtual ~Hero();
    bool collide(const Hero&);
    bool isDead() override;
    void setDead() override;
    const Coords &getMCoords() const;

    virtual float attack(Hero&, int) = 0;

    Coords mCoords;
    Effects mEffect;
    std::vector<Ability*> mAbility{2};
};

#endif //LOOP_HERO_HPP
