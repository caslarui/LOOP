//
// Created by caslarui on 16.12.2019.
//

#ifndef LOOP_GAME_HPP
#define LOOP_GAME_HPP

#include <fstream>
#include <iostream>
#include <queue>

#include "Map/Map.hpp"
#include "Characters/Heroes/Hero.hpp"
#include "Characters/Angels/Angel.hpp"

class Game {
public:
    explicit Game(const std::string&);

    void start();
    void finish();
    void update();

private:
    void heroStats();

    std::vector<Hero*> mHeroes;
    std::queue<char> mMovesBuffer;
    int mRounds;

};


#endif //LOOP_GAME_HPP
