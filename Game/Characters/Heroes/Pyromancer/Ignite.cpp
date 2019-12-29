//
// Created by caslarui on 18.12.2019.
//

#include <cmath>
#include <iostream>
#include "Ignite.hpp"
#include "../Rogue/Rogue.hpp"
#include "../Knight/Knight.hpp"
#include "Pyromancer.hpp"
#include "../Wizard/Wizard.hpp"
#include "../../../Map/Map.hpp"

Ignite::Ignite(Hero& owner) : Ability(owner) {
    baseDmg = 150.0f;
    effectDmg = 50.0f;
}

float Ignite::hit(Hero &enemy, int round) {
    if (!enemy.isDead()) {

        float dmg = baseDmg;
        float effect = effectDmg;
        float race = 0;
        float land = 0;
        round = 2;

        std::cout << "Ignite Base Damage : " << dmg << "\n";
        std::cout << "Ignite Effect Base Damage : " << effect << "\n";

        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'V') {
            land = 1.25f;
            std::cout << "Land Modifier : " << land << "\n";
            dmg *= land;
            effect *= land;
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

        std::cout << "Race Modifier : " << race << "\n";
        dmg *= race;
        effect *= race;

//        dmg += effect;
        dmg = std::round(dmg);
        enemy.mEffect.setEffect(Dmg, static_cast<int>(effect), round);
        std::cout << "Second Skill Total Damage : " << dmg << "\n\n ";
        return dmg;
    }
    return 0;
}

void Ignite::upgradeAbility() {
    baseDmg += baseDmgIncrease;
    effectDmg += effectDmgIncrease;
}

float Ignite::getBaseDmg(Hero &enemy, int round) {
    if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'V') {
        return std::round(baseDmg * 1.25f);
    }
    return std::round(baseDmg);
}
