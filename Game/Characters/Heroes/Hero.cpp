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

Hero::~Hero() {
    if (mAbility[0])
        delete mAbility[0];
    if (mAbility[1])
        delete mAbility[1];
    mAbility[0] = mAbility[1] = nullptr;
}
