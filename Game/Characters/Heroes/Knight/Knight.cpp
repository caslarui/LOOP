//
// Created by caslarui on 17.12.2019.
//

#include "Knight.hpp"

Knight::Knight(int _x, int _y) : Hero(_x, _y) {}

void Knight::attack(Hero &enemy) {
    for(Ability *skill : mAbility) {
        skill->hit(enemy);
    }

    if (enemy.mCurrentHp <= 0) {
        enemy.setDead();
    }
}

std::ostream &operator<<(std::ostream& os, const Knight& other) {
    os << "Knight{ " << other.mCoords.getMx() << " : " << other.mCoords.getMy() << " }\n";
    return os;
}
