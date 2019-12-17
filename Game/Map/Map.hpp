//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_MAP_HPP
#define LOOP_MAP_HPP


class Map {
public:
    int     getMm() const;
    int     getMn() const;
    Map *   getInstance();

    void setMMap(char **mMap);

    void setMm(int mM);

    void setMn(int mN);

private:
    Map     *instance = nullptr;
    Map();

    char**  mMap;
    int     mM;
    int     mN;
};


#endif //LOOP_MAP_HPP
