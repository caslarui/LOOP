//
// Created by caslarui on 18.12.2019.
//

#include <cmath>
#include "Paralysis.hpp"
#include "../Knight/Knight.hpp"
#include "Rogue.hpp"
#include "../Pyromancer/Pyromancer.hpp"
#include "../Wizard/Wizard.hpp"
#include "../../../Map/Map.hpp"

Paralysis::Paralysis() {
    baseDmg = 40.0f;
}

void Paralysis::hit(Hero &enemy, int round = 0) {
    if (!enemy.isDead()) {
        float dmg = baseDmg;
        round = 3;
        if (dynamic_cast<Knight*>(&enemy)) {
            dmg *= 0.8f;
        }
        if (dynamic_cast<Rogue*>(&enemy)) {
            dmg *= 0.9f;
        }
        if (dynamic_cast<Pyromancer*>(&enemy)) {
            dmg *= 1.2f;
        }
        if (dynamic_cast<Wizard*>(&enemy)) {
            dmg *= 1.25f;
        }
        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'W') {
            dmg *= 1.15f;
            round = 6;
        }
        dmg = std::round(dmg);
        enemy.takeDmg(static_cast<int>(dmg));
        enemy.mEffect.emplace_back(Dmg, dmg, round);
    }
}

void Paralysis::upgradeAbility() {

}
