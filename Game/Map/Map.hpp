//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_MAP_HPP
#define LOOP_MAP_HPP

#include <vector>
#include <utility>
#define MATRIX(type) std::vector<std::vector<type>>


class Map {
public:
    void setMMap(MATRIX(char));
    void setMm(int);
    void setMn(int);
    const MATRIX(char) &getMMap() const;

    int     getMm() const;
    int     getMn() const;
    static Map &getInstance();

private:
    Map();
//    ~Map();

    int     mM;
    int     mN;
    MATRIX(char)  mMap;
};


#endif //LOOP_MAP_HPP
