//
// Created by caslarui on 22.12.2019.
//

#include <ctgmath>
#include <iostream>
#include "Deflect.hpp"
#include "../Rogue/Rogue.hpp"
#include "../Knight/Knight.hpp"
#include "../Pyromancer/Pyromancer.hpp"
#include "Wizard.hpp"

Deflect::Deflect(Hero& owner) : Ability(owner) {
    basePct = 0.35f;
}

float Deflect::hit(Hero &enemy, int round) {
    if (!enemy.isDead() || enemy.mCurrentHp > 0) {
        if ( !(dynamic_cast<Wizard*>(&enemy)) ) {

            float dmg = 0;
            float race = 0;
            float land = 0;

            auto *wizard = dynamic_cast<Wizard*>(this->mOwner);
            for (int i = 0; i < 2; ++i) {
                dmg += enemy.mAbility[i]->getBaseDmg(*wizard, round);
            }

            assert(std::cout << "*Total Damage From Enemy : " << dmg << "\n\n";)
            assert(std::cout << "Deflect Dmg Pct : " << basePct << "\n";)
            assert(std::cout << "Deflect Dmg : " << dmg << " x " << basePct << " = ";)

            dmg *= basePct;

            assert(std::cout << dmg << "\n";)

            if (Map::getInstance().getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMy()] == 'D') {
                land = 1.1f;
                dmg *= land;
                assert(std::cout << "Land modifier : " << land << "\n";)
            }

            if (dynamic_cast<Rogue*>(&enemy)) {
                race = 1.2f;
            }
            if (dynamic_cast<Knight*>(&enemy)) {
                race = 1.4f;
            }
            if (dynamic_cast<Pyromancer*>(&enemy)) {
                race = 1.3f;
            }

            assert(std::cout << "Race modifier : " << race << "\n";)
            dmg *= race;

            dmg = std::round(dmg);
            assert(std::cout << "Second Skill Total Damage : " << dmg << "\n\n";)
            return dmg;
        }
    }
    return 0;
}

void Deflect::upgradeAbility() {
    if (basePct <= 0.7) {
        basePct += basePctIncrease;
    }
}

float Deflect::getBaseDmg(Hero &enemy, int round) {
    return 0;
}
