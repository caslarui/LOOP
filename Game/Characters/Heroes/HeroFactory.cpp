//
// Created by caslarui on 18.12.2019.
//

#include "HeroFactory.hpp"
#include "Knight/Knight.hpp"
#include "Rogue/Rogue.hpp"
#include "Pyromancer/Pyromancer.hpp"
#include "Wizard/Wizard.hpp"
#include "Knight/Execute.hpp"
#include "Knight/Slam.hpp"
#include "Rogue/Backstab.hpp"
#include "Rogue/Paralysis.hpp"
#include "Pyromancer/Fireblast.hpp"
#include "Pyromancer/Ignite.hpp"
#include "Wizard/Drain.hpp"

Knight* HeroFactory::getKnight(int x = -1, int y = -1) {
    auto *ret = new Knight(x, y);
    ret->mMaxHp = 900;
    ret->mCurrentHp = ret->mMaxHp;
    ret->mAbility[0] = new Execute();
    ret->mAbility[1] = new Slam();
    return ret;
}

Rogue *HeroFactory::getRogue(int x = -1, int y = -1) {
    auto *ret = new Rogue(x, y);
    ret->mMaxHp = 600;
    ret->mCurrentHp = ret->mMaxHp;
    ret->mAbility[0]= new Backstab;
    ret->mAbility[1] = new Paralysis;
    return ret;
}

Pyromancer *HeroFactory::getPyromancer(int x = -1, int y = -1) {
    auto *ret = new Pyromancer(x, y);
    ret->mMaxHp = 500;
    ret->mCurrentHp = ret->mMaxHp;
    ret->mAbility[0] = new Fireblast;
    ret->mAbility[1] = new Ignite;
    return ret;
}

Wizard *HeroFactory::getWizard(int x = -1, int y = -1) {
    auto *ret = new Wizard(x, y);
    ret->mMaxHp = 400;
    ret->mCurrentHp = ret->mMaxHp;
    ret->mAbility.resize(1, nullptr);
    ret->mAbility[0] = new Drain;
    return ret;
}

int HeroFactory::countXP(Hero &winner, Hero &looser) {
    return std::max(0, 200 - (winner.mLvl - looser.mLvl * 40));
}
