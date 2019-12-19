//
// Created by caslarui on 18.12.2019.
//

#include <cmath>
#include "Backstab.hpp"
#include "../Knight/Knight.hpp"
#include "Rogue.hpp"
#include "../Pyromancer/Pyromancer.hpp"
#include "../Wizard/Wizard.hpp"
#include "../../../Map/Map.hpp"

Backstab::Backstab() {
    baseDmg = 200.0f;
}

void Backstab::hit(Hero &enemy, int round = 0) {
    if (!enemy.isDead()) {
        float dmg = baseDmg;
        if (round % 3 == 0 &&
                Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'W') {
            dmg *= 1.5f;
        }

        if (dynamic_cast<Knight*>(&enemy)) {
            dmg *= .9f;
        }
        if (dynamic_cast<Rogue*>(&enemy)) {
            dmg *= 1.2f;
        }
        if (dynamic_cast<Pyromancer*>(&enemy)) {
            dmg *= 1.25f;
        }
        if (dynamic_cast<Wizard*>(&enemy)) {
            dmg *= 1.25f;
        }
        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'W') {
            dmg *= 1.15f;
        }
        dmg = std::round(dmg);
        enemy.takeDmg(static_cast<int>(dmg));
    }
}

void Backstab::upgradeAbility() {
    baseDmg += baseDmgIncrease;
}
