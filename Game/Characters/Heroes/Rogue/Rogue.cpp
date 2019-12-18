//
// Created by caslarui on 17.12.2019.
//

#include "Rogue.hpp"

Rogue::Rogue(int _x, int _y) : Hero(_x, _y) {}

void Rogue::attack(const Hero &) {}

std::ostream &operator<<(std::ostream &os, const Rogue *other) {
    os << "Rogue{ " << other->mCoords.getMx() << " : " << other->mCoords.getMy() << " }\n";
    return os;
}
