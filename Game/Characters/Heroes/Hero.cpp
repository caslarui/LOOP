//
// Created by caslarui on 17.12.2019.
//

#include "Hero.hpp"
#include "../Attributes/Stats.hpp"
#include "../Attributes/Coords.hpp"


bool Hero::collide(const Hero &enemy) {
    return this->mCoords == enemy.mCoords;
}

Hero::Hero(int _x, int _y) : Stats() {
    mCoords = Coords(_x, _y);
}

const Coords &Hero::getMCoords() const {
    return mCoords;
}

bool Hero::isDead() {
    return Stats::isDead();
}

void Hero::setDead() {
    Stats::setDead();
}
