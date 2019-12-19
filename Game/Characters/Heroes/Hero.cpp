//
// Created by caslarui on 17.12.2019.
//

#include "Hero.hpp"
#include "../Attributes/Stats.hpp"
#include "../Attributes/Effects.hpp"
#include "../Attributes/Coords.hpp"


bool Hero::collide(const Hero &enemy) {
    return this->mCoords == enemy.mCoords;
}

void Hero::setStrategy(Strategy &other) {
    mStrategy = &other;
}

Hero::Hero(int _x, int _y) : Stats() {
    mCoords = Coords(_x, _y);
    mStrategy = nullptr;
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
