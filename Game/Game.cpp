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
