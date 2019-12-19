//
// Created by caslarui on 18.12.2019.
//

#include <cmath>
#include "Drain.hpp"
#include "../Rogue/Rogue.hpp"
#include "../Knight/Knight.hpp"
#include "../Pyromancer/Pyromancer.hpp"
#include "Wizard.hpp"
#include "../../../Map/Map.hpp"

Drain::Drain() {
    basePct = 0.20f;
}

void Drain::hit(Hero &enemy, int round = 0) {
    if (!enemy.isDead()) {
        float basePercent = basePct;
        if (dynamic_cast<Rogue*>(&enemy)) {
            basePercent *= 0.8f;
        }
        if (dynamic_cast<Knight*>(&enemy)) {
            basePercent *= 1.2f;
        }
        if (dynamic_cast<Pyromancer*>(&enemy)) {
            basePercent *= 0.9f;
        }
        if (dynamic_cast<Wizard*>(&enemy)) {
            basePercent *= 1.05f;
        }
        float dmg = basePercent * std::min(static_cast<float>(enemy.mMaxHp) * 0.3f, static_cast<float>(enemy.mCurrentHp));
        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'D') {
            dmg *= 1.1f;
        }
        dmg = std::round(dmg);
        enemy.takeDmg(static_cast<int>(dmg));
    }
}

void Drain::upgradeAbility() {
    basePct += basePctIncrease;
}

