//
// Created by caslarui on 16.12.2019.
//
#include "Game.hpp"

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

        for (int i = 0; i < _p; ++i) {

        }

    }
    catch (const std::exception & e) {
        std::cerr << e.what();
        exit(EXIT_FAILURE);
    }
}

void Game::start() {

}

void Game::finish() {

}

void Game::update() {

}
