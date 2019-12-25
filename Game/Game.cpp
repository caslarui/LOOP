//
// Created by caslarui on 16.12.2019.
//
#include "Game.hpp"
#include "Characters/Heroes/HeroFactory.hpp"

Game::Game(const std::string & inputPath) {

    try {
        std::ifstream in(inputPath);

        // Verificam daca fisierul a fost deschis cu succes.
        if (!in.is_open()) {
            throw std::ios::failure("\nError opening file\n");
        }

        int _n;
        // Citim N din fisierul de input
        in >> _n;
        // Setam in clasa singleton N-ul
        Map::getInstance()->setMn(_n);

        // Citim M din fisierul de input
        int _m;
        in >> _m;
        // Setam in clasa singleton M-ul
        Map::getInstance()->setMm(_m);

        // Initializam un obiect temporar pentru harta
        std::vector<std::vector<char>> tmp(_n, std::vector<char>(_m));
        char c;

        // Citim caracter cu caracter si inscriem in obiectul temporar
        for (int i = 0; i < _n; ++i) {
            for (int j = 0; j < _m; ++j) {
               in >> c;
               tmp[i][j] = c;
            }
        }

        // Copiem din obiectul temporar in cel global
        Map::getInstance()->setMMap(tmp);
        // Stergem informatia din vectorul temporar.
        tmp.erase(tmp.begin(), tmp.end());

        // Citim numarul de eroi.
        int _p;
        in >> _p;

        // Cream lista cu eroi.
        char type;
        int x;
        int y;
        for (int i = 0; i < _p; ++i) {
            in >> type >> x >> y;
            switch (type) {
                case 'K' : this->mHeroes.push_back(HeroFactory::getKnight(x, y)); break;
                case 'W' : this->mHeroes.push_back(HeroFactory::getWizard(x, y)); break;
                case 'R' : this->mHeroes.push_back(HeroFactory::getRogue(x, y)); break;
                case 'P' : this->mHeroes.push_back(HeroFactory::getPyromancer(x, y)); break;
                default: std::cerr << "Invalid Hero type : " << type << std::endl; exit(EXIT_FAILURE);
            }
        }
        in >> mRounds;
        for (int i = 0; i < mRounds; ++i) {
            for (int j = 0; j < _p; ++j) {
                in >> type;
                mMovesBuffer.push(type);
            }
        }
    }
    catch (const std::exception & e) {
        std::cerr << e.what();
        exit(EXIT_FAILURE);
    }
}

void Game::start() {
    char move;

    for (int round = 0; round < mRounds; round++) {
        std::cout << "Round : " << round + 1 << std::endl;

        // Verificam daca exista efecte negative.
        for (auto& hero : mHeroes) {
            if (hero->mEffect.hasEffect()) {
                hero->takeDmg(hero->mEffect.getEffectDmg());
                hero->mEffect.decreaseTime();
            }
        }

        // Efectuam miscarile juctorilor pe mapa
        for (auto& hero : mHeroes) {
            if (hero->mEffect.isDisabled())
                continue;
            move = mMovesBuffer.front();
            hero->mCoords.move(move);
            mMovesBuffer.pop();
        }

        heroStats();

        // Verificam daca s-a depistat vreo coliziune
        for (int i = 0; i < mHeroes.size(); ++i) {
            for (int j = i + 1; j < mHeroes.size(); ++j) {
                if (mHeroes[i]->collide(*mHeroes[j])) {
                    battle(*mHeroes[i], *mHeroes[j], round);
                }
            }
        }

        // Actualizam statusurile jucatorilor.
        update();
    }
}

void Game::finish() {
    for (auto &hero : mHeroes) {
        if (dynamic_cast<Rogue*>(hero))
            std::cout << "R ";
        if (dynamic_cast<Knight*>(hero))
            std::cout << "K ";
        if (dynamic_cast<Pyromancer*>(hero))
            std::cout << "P ";
        if (dynamic_cast<Wizard*>(hero))
            std::cout << "W ";
        if (hero->isDead()) {
            std::cout << "dead\n";
            continue;
        }
        std::cout << hero->mLvl << " " << hero->mXp << " " << hero->mCurrentHp << " " << hero->mCoords.getMx() << " "
                                        << hero->mCoords.getMy() << "\n";
    }
}

void Game::update() {
    // Verificam daca exista eroi care au ramas fara viata
    //  daca acesta este depistat ii este setat flagul ca dead.
    for (auto& hero : mHeroes) {
        if (hero->mCurrentHp <= 0) {
            hero->setDead();
        }
    }

    // Verificam daca vreun eroi trebuie sa primeasca XP in urma unei lupte.
    if (!mXpBuffer.empty()) {
        Hero *current;
        int xp;
        int oldLvl;
        int newLvl;
        while(!mXpBuffer.empty()) {

            // Extragem eroul care va primi XP
            current = mXpBuffer.front().mHero;

            // Extragem cat Xp acesta ve primi
            xp = mXpBuffer.front().mGainedXp;

            oldLvl = current->mLvl;
            current->earnXP(xp);
            newLvl = current->mLvl;

            // Daca in urma XP primit acesta face lvl up, atunci si skillurile acestuia vor face lvl up.
            if (newLvl > oldLvl) {
                for (auto &skill : current->mAbility) {
                    for (int i = 0; i < (newLvl - oldLvl); ++i) {
                        skill->upgradeAbility();
                    }
                }
            }
            mXpBuffer.pop();
        }
    }
}

void Game::battle(Hero& fighter, Hero& enemy, int round) {
    if (!fighter.isDead() && !enemy.isDead()) {

        // Calculam dmg-ul pe care il va aplica primul luptator
        printBattle(fighter, enemy);
        float fighterDmg = fighter.attack(enemy, round);

        // Calculam dmg-ul pe care il va aplica cel de-al doilea luptator
        printBattle(enemy, fighter);
        float enemyDmg = enemy.attack(fighter, round);

        // In acelasi moment aplicam skilurile pe personaje
        fighter.takeDmg(static_cast<int>(enemyDmg));
        enemy.takeDmg(static_cast<int>(fighterDmg));

        // Verificam daca cineva a fost ucis in decursul luptei
        if (fighter.mCurrentHp == 0) {
            mXpBuffer.push({enemy, HeroFactory::countXP(enemy, fighter)});
        }
        if (enemy.mCurrentHp == 0) {
            mXpBuffer.push( {fighter, HeroFactory::countXP(fighter, enemy)} );
        }
    }
}

void Game::heroStats() {
        for (auto &mHero : mHeroes) {
            if (dynamic_cast<Rogue *>(mHero)) {
                auto *rog = dynamic_cast<Rogue *>(mHero);
                std::cout << *rog;
            }
            if (dynamic_cast<Wizard *>(mHero)) {
                auto *rog = dynamic_cast<Wizard *>(mHero);
                std::cout << *rog;
            }
            if (dynamic_cast<Knight *>(mHero)) {
                auto *rog = dynamic_cast<Knight *>(mHero);
                std::cout << &rog;
            }
            if (dynamic_cast<Pyromancer *>(mHero)) {
                auto *rog = dynamic_cast<Pyromancer *>(mHero);
                std::cout << &rog;
            }
        }
        std::cout << std::endl;
}

void Game::printBattle(Hero &fighter, Hero &enemy) {
    std::string type_fighter;
    std::string type_enemy;

    if (dynamic_cast<Rogue *>(&fighter)) {
        type_fighter = "Rogue";
    }
    if (dynamic_cast<Knight *>(&fighter)) {
        type_fighter = "Knight";
    }
    if (dynamic_cast<Pyromancer *>(&fighter)) {
        type_fighter = "Pyromancer";
    }
    if (dynamic_cast<Wizard *>(&fighter)) {
        type_fighter = "Wizard";
    }

    if (dynamic_cast<Rogue *>(&enemy)) {
        type_enemy = "Rogue";
    }
    if (dynamic_cast<Knight *>(&enemy)) {
        type_enemy = "Knight";
    }
    if (dynamic_cast<Pyromancer *>(&enemy)) {
        type_enemy = "Pyromancer";
    }
    if (dynamic_cast<Wizard *>(&enemy)) {
        type_enemy = "Wizard";
    }

    std::cout << "\n" << type_fighter << " is fighting with " << type_enemy << std::endl;
}
