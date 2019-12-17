//
// Created by caslarui on 17.12.2019.
//

#include "Effects.hpp"

void Effects::setEffect(EffectTypes _type = None, int _dmg = 0, int _time = 0) {
    Effects::mType = _type;
    Effects::mDmg = _dmg;
    Effects::mTime = _time;
}

Effects::Effects() {
    Effects::mType = None;
    Effects::mTime = 0;
    Effects::mDmg = 0;
}

bool Effects::isDisabled() {
    return mType == Disable;
}

void Effects::decreaseTime() {
    if (mType != None) {
        if (mTime >= 0) {
            --mTime;
        }
        if ( mTime < 0) {
            setEffect();
        }
    }
}

bool Effects::hasEffect() {
    return mType != None;
}


