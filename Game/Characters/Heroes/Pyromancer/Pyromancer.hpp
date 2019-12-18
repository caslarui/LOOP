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

    void attack(const Hero &) override;
    friend std::ostream&operator<<(std::ostream&, const Pyromancer&);
};


#endif //LOOP_PYROMANCER_HPP
