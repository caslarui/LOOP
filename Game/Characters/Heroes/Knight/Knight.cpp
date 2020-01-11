//
// Created by caslarui on 17.12.2019.
//

#include "Knight.hpp"

Knight::Knight(int _x, int _y) : Hero(_x, _y) {}

float Knight::attack(Hero &enemy, int round) {

    float dmg = 0;

    for (int i = 0; i < 2; ++i) {
        dmg += mAbility[i]->hit(enemy, round);
    }

    return dmg;
}

std::ostream &operator<<(std::ostream& os, Knight& other) {
    os << "Knight \t\t{" << other.mCoords.getMx() << " : " << other.mCoords.getMy() << "} | [" << other.isDead()
       << " | " << other.mCurrentHp << "\t | " << other.mLvl << "\t | "<< other.mXp << "\t | " << other.mEffect.getMType() <<
       "\t | " << other.mEffect.getEffectDmg() << "\t | " << other.mEffect.getMTime() << "\t]\n";
    return os;
}
