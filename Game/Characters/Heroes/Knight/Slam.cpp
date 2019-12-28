//
// Created by caslarui on 18.12.2019.
//

#include <cmath>
#include <iostream>
#include "Slam.hpp"
#include "../../../Map/Map.hpp"
#include "../Rogue/Rogue.hpp"
#include "../Pyromancer/Pyromancer.hpp"
#include "../Wizard/Wizard.hpp"
#include "Knight.hpp"

Slam::Slam(Hero& owner) : Ability(owner) {
    baseDmg = 100.0f;
}

float Slam::hit(Hero &enemy, int round) {
    if (!enemy.isDead()) {

        float dmg = baseDmg;
        float race = 0;
        float land = 0;

        std::cout << "Slam Base Damage : " << dmg << "\n";

        if (dynamic_cast<Knight*>(&enemy)) {
            race = 1.20f;
        }
        if (dynamic_cast<Rogue*>(&enemy)) {
            race = 0.8f;
        }
        if (dynamic_cast<Pyromancer*>(&enemy)) {
            race = 0.9f;
        }
        if (dynamic_cast<Wizard*>(&enemy)) {
            race = 1.05f;
        }

        std::cout << "Race Modifier : " << race << "\n";
        dmg *= race;

        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'L') {
            land = 1.15f;
            std::cout << "Land Modifier : " << land << "\n";
            dmg *= land;
        }

        dmg = std::round(dmg);

        enemy.mEffect.setEffect(Disable, 0, 1);
        std::cout << "Second Skill Total Damage : " << dmg << "\n\n";

        return dmg;
    }
    return 0;
}

void Slam::upgradeAbility() {
    baseDmg += baseDmgIncrease;
}

float Slam::getBaseDmg(Hero &enemy, int round) {
    return baseDmg;
}
