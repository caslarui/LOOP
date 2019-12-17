//
// Created by caslarui on 16.12.2019.
//

#ifndef LOOP_GAME_HPP
#define LOOP_GAME_HPP

//#include <string>
//#include <cstdlib>
//#include <iostream>
#include <fstream>

#include "Map/Map.hpp"
#include "Characters/Heroes/Hero.hpp"
#include "Characters/Angels/Angel.hpp"

class Game {
public:
    explicit Game(const std::string&);

    void start();
    void finish();
    void update();
};


#endif //LOOP_GAME_HPP
