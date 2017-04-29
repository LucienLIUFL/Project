#ifndef MYGAME_MAPLES_H
#define MYGAME_MAPLES_H

#include <string>
#include <iostream>
#include <sstream>

#include "cocos2d.h"

class Maples {
public:
    template <class T>
    static std::string toString(const T & value) {
        std::ostringstream stm;
        stm << value;
        return stm.str();
    }

    static void init(cocos2d::Layer * layer);
    static cocos2d::Animation * createAnimation(const std::string & filename, int num, double delay);
    static cocos2d::Sprite * createSprite();
    static void createEvent();
    static void debug(cocos2d::Layer * layer);
};


#endif //MYGAME_MAPLES_H
