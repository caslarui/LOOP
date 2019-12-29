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

typedef struct Buffer {
    Hero* mHero = nullptr;
    int mGainedXp = 0;

    Buffer(Hero &other, int xp) {
        mHero = &other;
        mGainedXp = xp;
    }

} Buffer;

class Game {
public:
    explicit Game(const std::string&);

    void start();
    void finish(const std::string&);
    void update();

    // Array where im saving a pointer to a Hero and the gained XP
    std::queue<Buffer> mXpBuffer;
private:

    void heroStats();
    void battle(Hero&, Hero&, int);
    void printBattle(Hero&, Hero&);

    // Array where im saving all the Heroes.
    std::vector<Hero*> mHeroes;

    // Queue of moves
    std::queue<char> mMovesBuffer;

    std::string mInputPath;

    // Number of rounds.
    int mRounds;

};


#endif //LOOP_GAME_HPP
