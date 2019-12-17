//
// Created by caslarui on 16.12.2019.
//
#include <iostream>
#include <fstream>
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
