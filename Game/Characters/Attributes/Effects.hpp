//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_EFFECTS_HPP
#define LOOP_EFFECTS_HPP

enum EffectTypes {
    None = 0, Dmg, Disable, Respawn
};

class Effects {
public:
    Effects();
    bool isDisabled();
    bool hasEffect();
    void setEffect(EffectTypes, int, int);
    void decreaseTime();

private:
    EffectTypes mType;
    int mDmg{};
    int mTime{};
};


#endif //LOOP_EFFECTS_HPP