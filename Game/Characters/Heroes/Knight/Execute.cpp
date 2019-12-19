//
// Created by caslarui on 18.12.2019.
//

#include <cmath>
#include "Execute.hpp"
#include "../../../Game.hpp"
#include "../Rogue/Rogue.hpp"
#include "../Pyromancer/Pyromancer.hpp"
#include "../Wizard/Wizard.hpp"

void Execute::hit(Hero &enemy, int round = 0) {
    if (!enemy.isDead()) {
        if (hpLimit * static_cast<float>(enemy.mMaxHp) > static_cast<float>(enemy.mCurrentHp)) {
            enemy.setDead();
            return;
        }
        float dmg = baseDmg;
        if (dynamic_cast<Rogue*>(&enemy)) {
            dmg *= 1.15f;
        }
        if (dynamic_cast<Pyromancer*>(&enemy)) {
            dmg *= 1.1f;
        }
        if (dynamic_cast<Wizard*>(&enemy)) {
            dmg *= 0.8f;
        }
        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'L') {
            dmg *= 1.15f;
        }
        dmg = std::round(dmg);
        enemy.takeDmg(static_cast<int>(dmg));
    }
}

void Execute::upgradeAbility() {
    baseDmg += baseDmgIncrease;
    if (hpLimit <= 40.0f) {
        hpLimit += hpLimitIncrease;
    }
}

Execute::Execute() {
    baseDmg = 200.0f;
    hpLimit = 0.2f;
}
