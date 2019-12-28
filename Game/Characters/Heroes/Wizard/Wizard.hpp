//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_WIZARD_HPP
#define LOOP_WIZARD_HPP

#include <ostream>
#include "../Hero.hpp"

class Wizard : public Hero {
public:
    Wizard(int, int);

    float attack(Hero &, int) override;

    friend std::ostream&operator<<(std::ostream&, Wizard&);
};


#endif //LOOP_WIZARD_HPP
