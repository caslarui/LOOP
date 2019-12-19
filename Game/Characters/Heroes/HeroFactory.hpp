//
// Created by caslarui on 18.12.2019.
//

#ifndef LOOP_HEROFACTORY_HPP
#define LOOP_HEROFACTORY_HPP


#include "Knight/Knight.hpp"
#include "Rogue/Rogue.hpp"
#include "Pyromancer/Pyromancer.hpp"
#include "Wizard/Wizard.hpp"
#include "Knight/Execute.hpp"
#include "Knight/Slam.hpp"
#include "Rogue/Backstab.hpp"
#include "Rogue/Paralysis.hpp"
#include "Pyromancer/Fireblast.hpp"
#include "Pyromancer/Ignite.hpp"
#include "Wizard/Drain.hpp"

class HeroFactory {
public:
    static Knight* getKnight(int, int);
    static Rogue* getRogue(int, int);
    static Pyromancer* getPyromancer(int, int);
    static Wizard* getWizard(int, int);
    static int countXP(Hero&, Hero&);
};


#endif //LOOP_HEROFACTORY_HPP
