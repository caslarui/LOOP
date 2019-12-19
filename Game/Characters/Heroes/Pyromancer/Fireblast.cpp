//
// Created by caslarui on 18.12.2019.
//

#include <cmath>
#include "Fireblast.hpp"
#include "../Knight/Knight.hpp"
#include "../Rogue/Rogue.hpp"
#include "Pyromancer.hpp"
#include "../Wizard/Wizard.hpp"
#include "../../../Map/Map.hpp"

Fireblast::Fireblast() {
    baseDmg = 350.0f;
}

void Fireblast::hit(Hero &enemy, int round = 0) {
    if (!enemy.isDead()) {
        float dmg = baseDmg;
        if (dynamic_cast<Rogue*>(&enemy)) {
            dmg *= 0.8f;
        }
        if (dynamic_cast<Knight*>(&enemy)) {
            dmg *= 1.2f;
        }
        if (dynamic_cast<Pyromancer*>(&enemy)) {
            dmg *= 0.9f;
        }
        if (dynamic_cast<Wizard*>(&enemy)) {
            dmg *= 1.05f;
        }
        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'V') {
            dmg *= 1.25f;
        }
        dmg = std::round(dmg);
        enemy.takeDmg(static_cast<int>(dmg));
    }
}

void Fireblast::upgradeAbility() {
    baseDmg += baseDmgIncrease;
}
