//
// Created by caslarui on 18.12.2019.
//

#include <cmath>
#include "Slam.hpp"
#include "../../../Map/Map.hpp"
#include "../Rogue/Rogue.hpp"
#include "../Pyromancer/Pyromancer.hpp"
#include "../Wizard/Wizard.hpp"
#include "Knight.hpp"

Slam::Slam() {
    baseDmg = 100.0f;
}

void Slam::hit(Hero &enemy) {
    if (!enemy.isDead()) {
        float dmg = baseDmg;
        if (dynamic_cast<Knight*>(&enemy)) {
            dmg *= 1.20f;
        }
        if (dynamic_cast<Rogue*>(&enemy)) {
            dmg *= 0.8f;
        }
        if (dynamic_cast<Pyromancer*>(&enemy)) {
            dmg *= 0.9f;
        }
        if (dynamic_cast<Wizard*>(&enemy)) {
            dmg *= 1.05f;
        }
        if (Map::getInstance()->getMMap()[mOwner->getMCoords().getMx()][mOwner->getMCoords().getMx()] == 'L') {
            dmg *= 1.15f;
        }
        dmg = std::round(dmg);
        enemy.takeDmg(static_cast<int>(dmg));
        enemy.mEffect.emplace_back(Disable, 0, 1);
    }
}

void Slam::upgradeAbility() {
    baseDmg += baseDmgIncrease;
}
