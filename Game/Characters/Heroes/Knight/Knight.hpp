//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_KNIGHT_HPP
#define LOOP_KNIGHT_HPP


#include <ostream>
#include "../Hero.hpp"

class Knight : public Hero {
public:
    Knight(int, int);

    float attack(Hero &, int) override;

    friend std::ostream&operator<<(std::ostream&, Knight&);
};


#endif //LOOP_KNIGHT_HPP
