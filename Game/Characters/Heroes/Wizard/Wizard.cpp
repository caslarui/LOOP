//
// Created by caslarui on 17.12.2019.
//

#include "Wizard.hpp"

Wizard::Wizard(int _x, int _y) : Hero(_x, _y) {}

void Wizard::attack(Hero &) {

}

std::ostream &operator<<(std::ostream &os, const Wizard &other) {
    os << "Wizard {" << other.mCoords.getMx() << " : " << other.mCoords.getMy() << "} | [" << other.mCurrentHp << " - " <<
                    other.mLvl<< "]\n";
    return os;
}
