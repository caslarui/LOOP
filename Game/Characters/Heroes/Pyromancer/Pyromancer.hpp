//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_PYROMANCER_HPP
#define LOOP_PYROMANCER_HPP


#include <ostream>
#include "../Hero.hpp"

class Pyromancer : public Hero {
public:
    Pyromancer(int, int);

    float attack(Hero &, int) override;
    friend std::ostream&operator<<(std::ostream&, Pyromancer&);
};


#endif //LOOP_PYROMANCER_HPP
