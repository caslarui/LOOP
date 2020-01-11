//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_MAP_HPP
#define LOOP_MAP_HPP

#include <vector>
#include <utility>


class Map {
public:
    int     getMm() const;
    int     getMn() const;
    static Map *getInstance();
    const std::vector<std::vector<char>> &getMMap() const;

    void setMMap(std::vector<std::vector<char>>);
    void setMm(int);
    void setMn(int);

private:
    Map();

    static Map *instance;
    int     mM;
    int     mN;
    std::vector<std::vector<char>>  mMap;
};


#endif //LOOP_MAP_HPP
