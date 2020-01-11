//
// Created by caslarui on 17.12.2019.
//

#ifndef LOOP_EFFECTS_HPP
#define LOOP_EFFECTS_HPP

enum EffectTypes {
    None = 0, Disable, Dmg
};

class Effects {
public:

    Effects();
    Effects(EffectTypes, int, int);
    bool isDisabled();
    bool hasEffect() const;
    void setEffect(EffectTypes, int, int);
    void decreaseTime();
    void clearEffects();
    int getEffectDmg();
    int getMTime() const;
    EffectTypes getMType() const;

private:
    EffectTypes mType;
    int mDmg;
    int mTime;
};


#endif //LOOP_EFFECTS_HPP
