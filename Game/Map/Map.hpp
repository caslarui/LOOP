//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_MAP_HPP
#define LOOP_MAP_HPP

#include <vector>


class Map {
public:
    int     getMm() const;
    int     getMn() const;
    static Map *   getInstance();

    void setMMap(std::vector<std::vector<char>>);
    void setMm(int);
    void setMn(int);

private:
    static Map* instance;
    Map();

    std::vector<std::vector<char>>  mMap;
    int     mM;
    int     mN;
};


#endif //LOOP_MAP_HPP
