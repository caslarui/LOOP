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
            assert(std::cout << "Hero HP Limit exceeded\nFirst Skill Total Damage : " << dmg << "\n";)
            enemy.mCurrentHp = 0;
            return dmg;
        }

        float race = 1;
        float land = 0;

        dmg = baseDmg;

        assert(std::cout << "Execute Base Damage : " << dmg << "\n";)

        if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMy()] == 'L') {
            land = 1.15f;
            assert(std::cout << "Land Modifier : " << land << "\n";)
            dmg *= land;
        }

        if (dynamic_cast<Rogue*>(&enemy)) {
            race = 1.15f;
        }
        if (dynamic_cast<Pyromancer*>(&enemy)) {
            race = 1.1f;
        }
        if (dynamic_cast<Wizard*>(&enemy)) {
            race = 0.8f;
        }

        assert(std::cout << "Race Modifier : " << race << "\n";)
        dmg *= race;

        dmg = std::round(dmg);

        assert(std::cout << "First Skill Total Damage : " << dmg << "\n\n";)

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
    if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMy()] == 'L') {
        return std::round(baseDmg * 1.15f);
    }
    return std::round(baseDmg);
}
