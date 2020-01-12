//
// Created by caslarui on 17.12.2019.
//

#include "Map.hpp"


//Map* Map::instance = nullptr;

Map &Map::getInstance() {
    static Map instance;
    return instance;
}

int Map::getMm() const {
    return mM;
}

int Map::getMn() const {
    return mN;
}

void Map::setMm(int _m) {
    Map::mM = _m;
}

void Map::setMn(int _n) {
    Map::mN = _n;
}

Map::Map() {}

void Map::setMMap(MATRIX(char) _map) {
    Map::mMap = std::move(_map);
}

const MATRIX(char) &Map::getMMap() const {
    return mMap;
}

//Map::~Map() {
//    delete instance;
//    instance = nullptr;
//}
