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
                default: std::cerr << "Invalid Hero type : " << type << std::endl; exit(1);
            }
        }
        in >> mRounds;
        for (int i = 0; i < mRounds; ++i) {
            for (int j = 0; j < _p; ++j) {
                in >> type;
                mMovesBuffer.push(type);
//                std::cout << type;
            }
//            std::cout << std::endl;
        }
    }
    catch (const std::exception & e) {
        std::cerr << e.what();
        exit(EXIT_FAILURE);
    }
}

void Game::start() {
    char move;
    heroStats();
    for (int i = 0; i < mRounds; i++) {
        std::cout << "Round : " << i + 1 << std::endl;
        for (auto& Hero : mHeroes) {
            move = mMovesBuffer.front();
            Hero->mCoords.move(move);
            mMovesBuffer.pop();
        }
        heroStats();
    }
}

void Game::finish() {

}

void Game::update() {

}

void Game::heroStats() {
        for (auto & mHero : mHeroes) {
            if (dynamic_cast<Rogue *>(mHero)) {
                Rogue *rog = dynamic_cast<Rogue *>(mHero);
                std::cout << rog << std::endl;
            }
            if (dynamic_cast<Wizard *>(mHero)) {
                Wizard *rog = dynamic_cast<Wizard *>(mHero);
                std::cout << rog << std::endl;
            }
            if (dynamic_cast<Knight *>(mHero)) {
                Knight *rog = dynamic_cast<Knight *>(mHero);
                std::cout << &rog << std::endl;
            }
            if (dynamic_cast<Pyromancer *>(mHero)) {
                Pyromancer *rog = dynamic_cast<Pyromancer *>(mHero);
                std::cout << &rog << std::endl;
            }
        }
}
