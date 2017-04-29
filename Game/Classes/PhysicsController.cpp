//
// Created by maples on 2/8/17.
//

#include "PhysicsController.h"

bool PhysicsController::onContactBegin(cocos2d::PhysicsContact & physicsContact, cocos2d::Layer * layer) {
    cocos2d::Node * nodeA = physicsContact.getShapeA()->getBody()->getNode();
    cocos2d::Node * nodeB = physicsContact.getShapeB()->getBody()->getNode();

    int maskA = nodeA->getPhysicsBody()->getContactTestBitmask();
    int maskB = nodeB->getPhysicsBody()->getContactTestBitmask();

    switch (maskA | maskB) {
        case 0b0110 : {
            cocos2d::Sprite * spriteA = dynamic_cast<cocos2d::Sprite *>(nodeA);
            cocos2d::Sprite * spriteB = dynamic_cast<cocos2d::Sprite *>(nodeB);

            cocos2d::log("%f, %f", spriteA->getPosition().x, spriteA->getPosition().y);
            cocos2d::log("%f, %f", spriteB->getPosition().x, spriteB->getPosition().y);
            break;
        }


        case 0b10010 : {
            if (maskA == 0b10000) {
                layer->removeChild(nodeB);
            } else {
                layer->removeChild(nodeA);
            }
            break;
        }
    }

    return true;
}