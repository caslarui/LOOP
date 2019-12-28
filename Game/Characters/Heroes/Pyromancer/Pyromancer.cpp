//
// Created by caslarui on 17.12.2019.
//

#include "Pyromancer.hpp"

Pyromancer::Pyromancer(int _x, int _y) : Hero(_x, _y) { }

float Pyromancer::attack(Hero &enemy, int round) {
    float dmg = 0;
    for (int i = 0; i < 2; ++i) {
        dmg += mAbility[i]->hit(enemy, round);
    }
    return dmg;
}

std::ostream &operator<<(std::ostream &os, Pyromancer &other) {
    os << "Pyromancer \t{" << other.mCoords.getMx() << " : " << other.mCoords.getMy() << "} | [" << other.isDead()
       << " | " << other.mCurrentHp << "\t | " << other.mLvl << "\t | " << other.mEffect.getMType() <<
       "\t | " << other.mEffect.getEffectDmg() << "\t | " << other.mEffect.getMTime() << "\t]\n";
    return os;
}
