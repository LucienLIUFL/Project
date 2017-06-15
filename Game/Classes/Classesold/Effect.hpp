//
//  Effect.hpp
//  Learn
//
//  Created by maples on 4/27/17.
//
//

#ifndef Effect_h
#define Effect_h

#include <string>

#include "cocos2d.h"

class Effect {
public:
    static bool Init() {
        auto spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();
        spriteFrameCache->addSpriteFramesWithFile("ImageRaw/explosion.plist");
        spriteFrameCache->addSpriteFramesWithFile("ImageRaw/textureOpaquePack.plist");
        return true;
    }

    static cocos2d::Sprite * CreateFlare(const cocos2d::Vec2 & pos) {
        auto flare = cocos2d::Sprite::create("ImageRaw/flare.jpg");

        flare->setBlendFunc(cocos2d::BlendFunc::ADDITIVE);
        flare->setOpacity(0);
        flare->setPosition(pos);
        flare->setRotation(-120);
        flare->setScale(0.2);

        auto opacityAnim = cocos2d::FadeTo::create(0.5, 255);
        auto opacityDim = cocos2d::FadeTo::create(1, 0);
        auto biggerAnim = cocos2d::ScaleBy::create(0.7, 1.2);
        auto biggerEase = cocos2d::EaseSineIn::create(biggerAnim);
        auto moveAnim = cocos2d::MoveBy::create(0.5, cocos2d::Vec2(328, 0));
        auto easeMove = cocos2d::EaseSineOut::create(moveAnim);
        auto rotateAnim = cocos2d::RotateBy::create(2.5, 90);
        auto easeRotate = cocos2d::EaseExponentialOut::create(rotateAnim);
        auto bigger = cocos2d::ScaleTo::create(0.5, 1);
        auto removeSelf = cocos2d::RemoveSelf::create();

        cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
        actions.pushBack(opacityAnim);
        actions.pushBack(opacityDim);
        actions.pushBack(biggerAnim);
        actions.pushBack(biggerEase);
        actions.pushBack(moveAnim);
        actions.pushBack(rotateAnim);
        actions.pushBack(removeSelf);

        auto action = cocos2d::Sequence::create(actions);

        flare->runAction(action);
        flare->runAction(easeMove);
        flare->runAction(easeRotate);
        flare->runAction(bigger);
        return flare;
    }

    static cocos2d::Sprite * CreateHitOnce(const cocos2d::Vec2 & pos) {
        auto spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();
        auto hit = cocos2d::Sprite::createWithSpriteFrame(spriteFrameCache->getSpriteFrameByName("hit.png"));
        auto scaleBy = cocos2d::ScaleBy::create(0.3, 1.0, 1.0);
        auto fadeOut = cocos2d::FadeOut::create(0.3);
        auto action = cocos2d::Sequence::create(scaleBy, fadeOut, cocos2d::RemoveSelf::create(), nullptr);
        hit->runAction(action);
        hit->setBlendFunc(cocos2d::BlendFunc::ADDITIVE);
        hit->setPosition(pos);
        return hit;
    }

    static cocos2d::Sprite * CreateExplosionOnce(const cocos2d::Vec2 & pos) {
        const double delay = 0.04;

        auto spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();
        auto explosion = cocos2d::Animation::create();

        auto spark0 = spriteFrameCache->getSpriteFrameByName("explode1.png");
        auto spark1 = spriteFrameCache->getSpriteFrameByName("explode2.png");
        auto spark2 = spriteFrameCache->getSpriteFrameByName("explode3.png");

        explosion->addSpriteFrame(spark0);
        explosion->addSpriteFrame(spark1);
        explosion->addSpriteFrame(spark2);

        for (int i = 1; i <= 35; i++) {
            std::string name;
            if (i < 10) {
                name = std::string("explosion_0") + std::to_string(i) + ".png";
            } else {
                name = std::string("explosion_") + std::to_string(i) + ".png";
            }
            explosion->addSpriteFrame(spriteFrameCache->getSpriteFrameByName(name));
        }

        explosion->setDelayPerUnit(delay);
        explosion->setRestoreOriginalFrame(true);

        auto explode = cocos2d::Animate::create(explosion);
        auto action = cocos2d::Sequence::create(explode, cocos2d::RemoveSelf::create(), nullptr);

        auto explodeSprite = cocos2d::Sprite::createWithSpriteFrame(spark0);
        explodeSprite->runAction(action);
        explodeSprite->setBlendFunc(cocos2d::BlendFunc::ADDITIVE);
        explodeSprite->setPosition(pos);
        return explodeSprite;
    }
};

#endif /* Effect_h */
