//
// Created by caslarui on 18.12.2019.
//

#ifndef LOOP_SLAM_HPP
#define LOOP_SLAM_HPP


#include "../Ability.hpp"

class Slam : public Ability{
public:
    Slam();
    void hit(Hero&) override;
    void upgradeAbility() override;

    float baseDmg;
    constexpr static const float baseDmgIncrease = 40.0f;
};


#endif //LOOP_SLAM_HPP
