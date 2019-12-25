//
// Created by caslarui on 18.12.2019.
//

#ifndef LOOP_SLAM_HPP
#define LOOP_SLAM_HPP


#include "../Ability.hpp"

class Slam : public Ability{
public:
    explicit Slam(Hero&);
    float hit(Hero&, int) override;
    void upgradeAbility() override;

private:
    float baseDmg;
    constexpr static float baseDmgIncrease = 40.0f;
};


#endif //LOOP_SLAM_HPP
