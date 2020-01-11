//
// Created by caslarui on 18.12.2019.
//

#include <cmath>
#include <iostream>
#include "Paralysis.hpp"
#include "../Knight/Knight.hpp"
#include "Rogue.hpp"
#include "../Pyromancer/Pyromancer.hpp"
#include "../Wizard/Wizard.hpp"

Paralysis::Paralysis(Hero& owner) : Ability(owner) {
    baseDmg = 40.0f;
}

float Paralysis::hit(Hero &enemy, int round) {
    if (!enemy.isDead()) {

        float dmg = baseDmg;
        float race = 0;
        float land = 0;
        round = 3;

        assert(std::cout << "Paralysis base damage : " << dmg << "\n";)

        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMy()] == 'W') {
            land = 1.15f;
            round = 6;
            assert(std::cout << "Land modifier : " << land << "\n";)
            dmg *= land;
        }

        if (dynamic_cast<Knight*>(&enemy)) {
            race = 0.8f;
        }
        if (dynamic_cast<Rogue*>(&enemy)) {
            race = 0.9f;
        }
        if (dynamic_cast<Pyromancer*>(&enemy)) {
            race = 1.2f;
        }
        if (dynamic_cast<Wizard*>(&enemy)) {
            race = 1.25f;
        }

        assert(std::cout << "Race modifier : " << race << "\n";)
        dmg *= race;

        dmg = std::round(dmg);
        assert(std::cout << "Second Skill Total Damage : " << dmg << "\n\n";)
        enemy.mEffect.setEffect(Dmg, static_cast<int>(dmg), round);
        return dmg;
    }
    return 0;
}

void Paralysis::upgradeAbility() {
    baseDmg += baseDmgIncrease;
}

float Paralysis::getBaseDmg(Hero &enemy, int round) {
    if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMy()] == 'W') {
        return std::round(baseDmg * 1.15f);
    }
    return std::round(baseDmg);
}
