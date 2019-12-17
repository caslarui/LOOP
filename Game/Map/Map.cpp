//
// Created by caslarui on 17.12.2019.
//

#include "Map.hpp"

Map * Map::getInstance() {
    if (this->instance == nullptr) {
        this->instance = new Map();
    }
    return this->instance;
}

int Map::getMm() const {
    return mM;
}

int Map::getMn() const {
    return mN;
}

void Map::setMMap(char** _map) {
    Map::mMap = _map;
}

void Map::setMm(int _m) {
    Map::mM = _m;
}

void Map::setMn(int _n) {
    Map::mN = _n;
}
