//
// Created by caslarui on 16.12.2019.
//

#include "Game/Game.hpp"

int main(int argc, char** argv) {

    // Citim  datele din fisierul de input
    Game mGame(argv[1]);

    mGame.start();

    // Distrugem datele alocate si afisam output.
    mGame.finish(argv[2]);

    return EXIT_SUCCESS;
}

