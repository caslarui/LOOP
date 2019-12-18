//
// Created by caslarui on 17.12.2019.
//

#include "Knight.hpp"

Knight::Knight(int _x, int _y) : Hero(_x, _y) {}

void Knight::attack(const Hero &enemy) {

}

std::ostream &operator<<(std::ostream os, const Knight& other) {

}

//Knight& Knight::operator=(const Knight& other) {
//    mCoords = other.getMCoords();
//    mStrategy = other.mStrategy;
//    mAbility = other.mAbility;
//    if (other.getMEffect().hasEffect()) {
//        mEffect = other.getMEffect();
//    }
//}
