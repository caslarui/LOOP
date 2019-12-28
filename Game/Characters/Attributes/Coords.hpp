//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_COORDS_HPP
#define LOOP_COORDS_HPP


class Coords {
public:
    Coords();
    Coords(int mX, int mY);
    bool operator==(const Coords&);
    int getMx() const;
    int getMy() const;
    void move(char);
    void setCoords(int, int);

private:
    int mX;
    int mY;
};


#endif //LOOP_COORDS_HPP
