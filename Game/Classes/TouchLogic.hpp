//
//  TouchLogic.hpp
//  Learn
//
//  Created by maples on 4/29/17.
//
//

#ifndef TouchLogic_h
#define TouchLogic_h

#include "cocos2d.h"

class TouchLogic
{
public:
    static bool OnTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
    {
        cocos2d::Node * target = event->getCurrentTarget();
        cocos2d::Vec2 touchLocation = touch->getLocation();
        cocos2d::Vec2 locationInNode = target->convertToNodeSpace(touchLocation);
        cocos2d::Size size = target->getContentSize();
        cocos2d::Rect rect = cocos2d::Rect(0, 0, size.width, size.height);
        return rect.containsPoint(locationInNode);
    }

    static void OnTouchMoved(cocos2d::Touch * touch, cocos2d::Event * event)
    {
        cocos2d::Node * target =  event->getCurrentTarget();
        target->setPosition(target->getPosition() + touch->getDelta());
    }
};

#endif /* TouchLogic_h */
