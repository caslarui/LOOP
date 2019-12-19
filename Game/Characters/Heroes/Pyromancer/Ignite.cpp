//
// Created by caslarui on 18.12.2019.
//

#include <cmath>
#include "Ignite.hpp"
#include "../Rogue/Rogue.hpp"
#include "../Knight/Knight.hpp"
#include "Pyromancer.hpp"
#include "../Wizard/Wizard.hpp"
#include "../../../Map/Map.hpp"

Ignite::Ignite() {
    baseDmg = 150.0f;
    effectDmg = 50.0f;
}

void Ignite::hit(Hero &enemy, int round = 0) {
    if (!enemy.isDead()) {
        float dmg = baseDmg;
        float effect = effectDmg;
        if (dynamic_cast<Rogue*>(&enemy)) {
            dmg *= 0.8f;
            effect *= 0.8f;
        }
        if (dynamic_cast<Knight*>(&enemy)) {
            dmg *= 1.2f;
            effect *= 1.2f;
        }
        if (dynamic_cast<Pyromancer*>(&enemy)) {
            dmg *= 0.9f;
            effect *= 0.9f;
        }
        if (dynamic_cast<Wizard*>(&enemy)) {
            dmg *= 1.05f;
            effect *= 1.05f;
        }
        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'V') {
            dmg *= 1.25f;
            effect *= 1.25f;
        }
        dmg = std::round(dmg);
        enemy.takeDmg(static_cast<int>(dmg));
        enemy.mEffect.emplace_back(Dmg, effect, round);
    }
}

void Ignite::upgradeAbility() {
    baseDmg += baseDmgIncrease;
    effectDmg += effectDmgIncrease;
}
