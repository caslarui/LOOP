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

        assert(std::cout << "Drain Base Percent : " << basePercent << std::endl;)
        assert(std::cout << "Race modifier : " << race << "\n";)
        basePercent *= race;

        float dmg = basePercent * std::min(static_cast<float>(enemy.mMaxHp) * 0.3f, static_cast<float>(enemy.mCurrentHp));

        assert(std::cout << "Drain Base Damage : " <<  basePercent << " x " << std::min(static_cast<float>(enemy.mMaxHp) * 0.3f,
                static_cast<float>(enemy.mCurrentHp)) << " = "<< dmg << std::endl;)

        if (Map::getInstance().getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMy()] == 'D') {
            land = 1.1f;
            assert(std::cout << "Land modifier : " << land << "\n";)
            dmg *= land;
        }

        dmg = std::round(dmg);

        assert(std::cout << "Drain Total Damage : " << dmg << "\n\n";)

        return dmg;
    }
    return 0;
}

void Drain::upgradeAbility() {
    basePct += basePctIncrease;
}

float Drain::getBaseDmg(Hero &enemy, int round) {
    float basePercent = basePct;
    float dmg;
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
    dmg = std::roundf(basePercent * std::min(static_cast<float>(enemy.mMaxHp) * 0.3f, static_cast<float>(enemy.mCurrentHp)));
    if (Map::getInstance().getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMy()] == 'D') {
        dmg *= 1.1f;
    }
    return std::round(dmg);
}

