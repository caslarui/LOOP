//
// Created by caslarui on 18.12.2019.
//

#include <cmath>
#include <iostream>
#include "Backstab.hpp"
#include "../Knight/Knight.hpp"
#include "Rogue.hpp"
#include "../Pyromancer/Pyromancer.hpp"
#include "../Wizard/Wizard.hpp"
#include "../../../Map/Map.hpp"

Backstab::Backstab(Hero& owner) : Ability(owner) {
    baseDmg = 200.0f;
}

float Backstab::hit(Hero &enemy, int round = 0) {
    if (!enemy.isDead()) {
        float dmg = baseDmg;
        float race = 0;
        float land = 0;
        float extra = 0;

        std::cout << "Backstab base damage : " << dmg << "\n";
        if (round % 3 == 0 &&
                Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'W') {
            extra = 1.5f;
        }

        if (dynamic_cast<Knight*>(&enemy)) {
            race = .9f;
        }
        if (dynamic_cast<Rogue*>(&enemy)) {
            race = 1.2f;
        }
        if (dynamic_cast<Pyromancer*>(&enemy)) {
            race = 1.25f;
        }
        if (dynamic_cast<Wizard*>(&enemy)) {
            race = 1.25f;
        }

        if (extra != 0) {
            std::cout << "Critical modifier : " << extra << "\n";
            dmg *= extra;
        }

        std::cout << "Race modifier : " << race << "\n";
        dmg *= race;

        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'W') {
            land = 1.15f;
            std::cout << "Land modifier : " << land << "\n";
            dmg *= land;
        }

        dmg = std::round(dmg);
        std::cout << "First Skill Total Damage : " << dmg << "\n\n ";

        return dmg;
    }
    return 0;
}

void Backstab::upgradeAbility() {
    baseDmg += baseDmgIncrease;
}

float Backstab::getBaseDmg(Hero &enemy, int round) {
    if (round % 3 == 0 &&
        Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'W') {
        return baseDmg * 1.5f;
    }
    return baseDmg;
}
