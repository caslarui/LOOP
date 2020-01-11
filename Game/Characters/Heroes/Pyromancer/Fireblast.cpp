//
// Created by caslarui on 18.12.2019.
//

#include <cmath>
#include <iostream>
#include "Fireblast.hpp"
#include "../Knight/Knight.hpp"
#include "../Rogue/Rogue.hpp"
#include "Pyromancer.hpp"
#include "../Wizard/Wizard.hpp"

Fireblast::Fireblast(Hero& owner) : Ability(owner) {
    baseDmg = 350.0f;
}

float Fireblast::hit(Hero &enemy, int round) {
    if (!enemy.isDead()) {

        float dmg = baseDmg;
        float race = 0;
        float land = 0;

        assert(std::cout << "Fireblast Base Damage : " << dmg << "\n";)

        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMy()] == 'V') {
            land = 1.25f;
            assert(std::cout << "Land Modifier : " << land << "\n";)
            dmg *= land;
        }

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

        assert(std::cout << "Race Modifier : " << race << "\n";)
        dmg *= race;

        dmg = std::roundf(dmg);
        assert(std::cout << "First Skill Total Damage : " << dmg << "\n\n";)
        return dmg;
    }
    return 0;
}

void Fireblast::upgradeAbility() {
    baseDmg += baseDmgIncrease;
}

float Fireblast::getBaseDmg(Hero &enemy, int round) {
    if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMy()] == 'V') {
        return std::round(baseDmg * 1.25f);
    }
    return std::round(baseDmg);
}
