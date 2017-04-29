//
// Created by maples on 2/8/17.
//

#ifndef MYGAME_PHYSICSCONTROLLER_H
#define MYGAME_PHYSICSCONTROLLER_H

#include "cocos2d.h"

class PhysicsController {
public:
    static bool onContactBegin(cocos2d::PhysicsContact &, cocos2d::Layer *);
};


#endif //MYGAME_PHYSICSCONTROLLER_H
