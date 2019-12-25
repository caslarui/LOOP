//
// Created by caslarui on 18.12.2019.
//

#include <cmath>
#include <iostream>
#include "Drain.hpp"
#include "../Rogue/Rogue.hpp"
#include "../Knight/Knight.hpp"
#include "../Pyromancer/Pyromancer.hpp"
#include "Wizard.hpp"
#include "../../../Map/Map.hpp"

Drain::Drain(Hero& owner) : Ability(owner) {
    basePct = 0.20f;
}

float Drain::hit(Hero &enemy, int round) {
    if (!enemy.isDead()) {
        float basePercent = basePct;
        float race = 0;
        float land = 0;
        if (dynamic_cast<Rogue*>(&enemy)) {
            race = 0.8f;
        }
        if (dynamic_cast<Knight*>(&enemy)) {
            race = 1.2f;
        }
        if (dynamic_cast<Pyromancer*>(&enemy)) {
            race = 0.9f;
        }
        if (dynamic_cast<Wizard*>(&enemy)) {
            race = 1.05f;
        }
        std::cout << "Drain Base Percent : " << basePercent << std::endl;
        basePercent *= race;
        float dmg = basePercent * std::min(static_cast<float>(enemy.mMaxHp) * 0.3f, static_cast<float>(enemy.mCurrentHp));
        std::cout << "Drain Base Damage : " << dmg << std::endl;
        std::cout << "Race modifier : " << race << "\n";

        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'D') {
            land = 1.1f;
            std::cout << "Land modifier : " << land << "\n";
            dmg *= land;
        }
        dmg = std::round(dmg);
//        enemy.takeDmg(static_cast<int>(dmg));
        return dmg;
    }
    return 0;
}

void Drain::upgradeAbility() {
    basePct += basePctIncrease;
}

