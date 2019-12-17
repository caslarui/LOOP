//
// Created by caslarui on 17.12.2019.
//

#include "Hero.hpp"

bool Hero::collide(const Hero &enemy) {
    return this->mCoords == enemy.mCoords;
}

void Hero::setStrategy(Strategy &other) {
    this->mStrategy = &other;
}
