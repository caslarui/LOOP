//
// Created by caslarui on 18.12.2019.
//

#include <cmath>
#include "Execute.hpp"
#include "../../../Game.hpp"
#include "../Rogue/Rogue.hpp"
#include "../Pyromancer/Pyromancer.hpp"
#include "../Wizard/Wizard.hpp"

float Execute::hit(Hero &enemy, int round) {
    if (!enemy.isDead()) {
        float dmg;
        if (hpLimit * static_cast<float>(enemy.mMaxHp) > static_cast<float>(enemy.mCurrentHp)) {
            dmg = static_cast<float>(enemy.mCurrentHp);
            std::cout << "Hero HP Limit exceeded\nFirst Skill Total Damage : " << dmg << "\n";
            enemy.mCurrentHp = 0;
            return dmg;
        }

        float race = 1;
        float land = 0;
        dmg = baseDmg;

        std::cout << "Execute Base Damage : " << dmg << "\n";

        if (dynamic_cast<Rogue*>(&enemy)) {
            race = 1.15f;
        }
        if (dynamic_cast<Pyromancer*>(&enemy)) {
            race = 1.1f;
        }
        if (dynamic_cast<Wizard*>(&enemy)) {
            race = 0.8f;
        }

        std::cout << "Race Modifier : " << race << "\n";
        dmg *= race;

        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'L') {
            land = 1.15f;
            std::cout << "Land Modifier : " << land << "\n";
            dmg *= land;
        }

        dmg = std::round(dmg);

        std::cout << "First Skill Total Damage : " << dmg << "\n\n";

        return dmg;
    }
}

void Execute::upgradeAbility() {
    baseDmg += baseDmgIncrease;
    if (hpLimit <= 40.0f) {
        hpLimit += hpLimitIncrease;
    }
}

Execute::Execute(Hero& owner) : Ability(owner) {
    baseDmg = 200.0f;
    hpLimit = 0.2f;
}

float Execute::getBaseDmg(Hero &enemy, int round) {
    if (hpLimit * static_cast<float>(enemy.mMaxHp) > static_cast<float>(enemy.mCurrentHp)) {
        return static_cast<float>(enemy.mCurrentHp);
    }
    return baseDmg;
}
