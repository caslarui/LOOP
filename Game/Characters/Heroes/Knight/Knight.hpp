//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_KNIGHT_HPP
#define LOOP_KNIGHT_HPP


#include "../Hero.hpp"

class Knight : private Hero {
public:
    Knight(int, int);

    void attack(const Hero &) override;
};


#endif //LOOP_KNIGHT_HPP
