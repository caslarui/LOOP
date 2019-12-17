//
// Created by caslarui on 16.12.2019.
//

#include <cstdlib>

#include "Game/Game.hpp"

int main(int argc, char** argv) {

    // Citim  datele din fisierul de input
    Game mGame(argv[1]);

    mGame.start();

    // Distrugem datele alocate si afisam output.
    mGame.finish();

    return EXIT_SUCCESS;
}

