//
// Created by caslarui on 17.12.2019.
//

#include "Pyromancer.hpp"

Pyromancer::Pyromancer(int _x, int _y) : Hero(_x, _y) { }

void Pyromancer::attack(const Hero &) { }

std::ostream &operator<<(std::ostream &os, const Pyromancer &other) {
    os << "Pyromancer{ " << other.mCoords.getMx() << " : " << other.mCoords.getMy() << " }\n";
    return os;
}
