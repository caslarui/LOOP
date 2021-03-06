//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_ROGUE_HPP
#define LOOP_ROGUE_HPP

#include <ostream>
#include "../Hero.hpp"
#include "../../../Game.hpp"

class Rogue : public Hero {
public:
    Rogue(int, int);

    float attack(Hero &, int) override;

    friend std::ostream&operator<<(std::ostream&, Rogue&);
};


#endif //LOOP_ROGUE_HPP
