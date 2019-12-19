//
// Created by caslarui on 17.12.2019.
//

#include "Knight.hpp"
#include "../HeroFactory.hpp"
#include "../../../Game.hpp"

Knight::Knight(int _x, int _y) : Hero(_x, _y) {}

void Knight::attack(Hero &enemy, int round = 0) {
    for(Ability *skill : mAbility) {
        skill->hit(enemy, round);
    }

    if (enemy.mCurrentHp <= 0) {
        enemy.setDead();
//        Game::mXpBuffer.emplace_back(this, HeroFactory::countXP(*this, enemy));
    }
}

std::ostream &operator<<(std::ostream& os, const Knight& other) {
    os << "Knight{ " << other.mCoords.getMx() << " : " << other.mCoords.getMy() << " }\n";
    return os;
}
