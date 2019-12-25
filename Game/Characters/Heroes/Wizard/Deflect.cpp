//
// Created by caslarui on 22.12.2019.
//

#include <ctgmath>
#include <iostream>
#include "Deflect.hpp"
#include "../Rogue/Rogue.hpp"
#include "../Knight/Knight.hpp"
#include "../Pyromancer/Pyromancer.hpp"
#include "../../../Map/Map.hpp"

Deflect::Deflect(Hero& owner) : Ability(owner) {
    basePct = 0.35f;
}

float Deflect::hit(Hero &enemy, int round) {
    if (!enemy.isDead()) {
        if ( !(dynamic_cast<Wizard*>(&enemy)) ) {
            float dmg = 0;
            float race = 0;
            float land = 0;
            for (int i = 0; i < 2; ++i) {
                dmg += enemy.mAbility[i]->hit(*(this->mOwner), round);
            }
            dmg *= basePct;
            dmg = std::round(dmg);
            std::cout << "Deflect Dmg : " << dmg << "\n";
            if (dynamic_cast<Rogue*>(&enemy)) {
                race = 1.2f;
            }
            if (dynamic_cast<Knight*>(&enemy)) {
                race = 1.4f;
            }
            if (dynamic_cast<Pyromancer*>(&enemy)) {
                race = 1.3f;
            }
            if (Map::getInstance()->getMMap()[enemy.getMCoords().getMx()][enemy.getMCoords().getMx()] == 'D') {
                land = 1.1f;
            }

            std::cout << "Race modifier : " << race << "\n";
            dmg *= race;

            if (land != 0) {
                dmg *= land;
                std::cout << "Land modifier : " << land << "\n";
            }
            dmg = std::round(dmg);
            std::cout << "Second Skill Total Damage : " << dmg << "\n\n";
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
