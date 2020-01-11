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

Backstab::Backstab(Hero& owner) : Ability(owner) {
    baseDmg = 200.0f;
}

float Backstab::hit(Hero &enemy, int round = 0) {
    if (!enemy.isDead()) {
        float dmg = baseDmg;
        float race = 0;
        float land = 0;
        float extra = 0;

        assert(std::cout << "Backstab base damage : " << dmg << "\n";)
        if (round % 3 == 0 &&
                Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMy()] == 'W') {
            extra = 1.5f;
            assert(std::cout << "Critical modifier : " << extra << "\n";)
            dmg *= extra;
        }

        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMy()] == 'W') {
            land = 1.15f;
            assert(std::cout << "Land modifier : " << land << "\n";)
            dmg *= land;
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

        assert(std::cout << "Race modifier : " << race << "\n";)
        dmg *= race;

        dmg = std::round(dmg);
        assert(std::cout << "First Skill Total Damage : " << dmg << "\n\n ";)

        return dmg;
    }
    return 0;
}

void Backstab::upgradeAbility() {
    baseDmg += baseDmgIncrease;
}

float Backstab::getBaseDmg(Hero &enemy, int round) {
    float dmg = baseDmg;
    if (round % 3 == 0 &&
        Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMy()] == 'W') {
        dmg *= 1.5f;
        dmg *= 1.15f;
    }
    return std::round(dmg);
}
