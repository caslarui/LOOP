//
// Created by caslarui on 17.12.2019.
//

#include "Map.hpp"


Map* Map::instance = nullptr;

Map * Map::getInstance() {
    if (instance == nullptr) {
        instance = new Map();
    }
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

void Map::setMMap(std::vector<std::vector<char>> _map) {
    Map::mMap = std::move(_map);
}

const std::vector<std::vector<char>> &Map::getMMap() const {
    return mMap;
}
