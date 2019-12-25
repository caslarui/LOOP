//
// Created by caslarui on 17.12.2019.
//

#include "Knight.hpp"
#include "../HeroFactory.hpp"
#include "../../../Game.hpp"

Knight::Knight(int _x, int _y) : Hero(_x, _y) {}

float Knight::attack(Hero &enemy, int round) {
    float dmg = 0;
    for (int i = 0; i < 2; ++i) {
        dmg += mAbility[i]->hit(enemy, round);
    }
    return dmg;
}

std::ostream &operator<<(std::ostream& os, const Knight& other) {
    os << "Knight {" << other.mCoords.getMx() << " : " << other.mCoords.getMy() << "} | [" << other.mCurrentHp << " - " <<
       other.mLvl<< "]\n";
    return os;
}
