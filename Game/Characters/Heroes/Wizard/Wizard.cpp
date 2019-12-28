//
// Created by caslarui on 17.12.2019.
//

#include "Wizard.hpp"

Wizard::Wizard(int _x, int _y) : Hero(_x, _y) {}

float Wizard::attack(Hero &enemy, int round) {
    float dmg = 0;
    for (int i = 0; i < 2; ++i) {
        dmg += mAbility[i]->hit(enemy, round);
    }
    return dmg;
}

std::ostream &operator<<(std::ostream &os,  Wizard &other) {
    os << "Wizard \t\t{" << other.mCoords.getMx() << " : " << other.mCoords.getMy() << "} | [" << other.isDead()
                << " | " << other.mCurrentHp << "\t | " << other.mLvl << "\t | " << other.mEffect.getMType() <<
                "\t | " << other.mEffect.getEffectDmg() << "\t | " << other.mEffect.getMTime() << "\t]\n";
    return os;
}
