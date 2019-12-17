//
// Created by caslarui on 17.12.2019.
//

#include "Coords.hpp"

bool Coords::operator==(const Coords &other) {
    return mX == other.getMx() && mY == other.getMy();
}

Coords::Coords() {
    mX = mY = -1;
}

int Coords::getMx() const {
    return mX;
}

int Coords::getMy() const {
    return mY;
}

Coords::Coords(int _x, int _y) : mX(_x), mY(_y) {}
