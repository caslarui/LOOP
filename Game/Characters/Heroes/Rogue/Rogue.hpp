//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_ROGUE_HPP
#define LOOP_ROGUE_HPP

#include "../Hero.hpp"

class Rogue : public Hero {
public:
    Rogue(int, int);

    void attack(const Hero &) override;
};


#endif //LOOP_ROGUE_HPP
