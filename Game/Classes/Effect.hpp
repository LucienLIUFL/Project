//
//  Effect.hpp
//  Learn
//
//  Created by maples on 4/27/17.
//
//

#ifndef Effect_h
#define Effect_h

#include "cocos2d.h"

#include "Resource.hpp"

class Effect {
public:
    static cocos2d::Sprite * CreateFlare()
    {
        auto flare = cocos2d::Sprite::create(Resource::FLARE);
        auto vs = cocos2d::Director::getInstance()->getVisibleSize();

        flare->setBlendFunc(cocos2d::BlendFunc::ADDITIVE);
        flare->setOpacity(0);
        flare->setPosition(cocos2d::Vec2(-30, vs.height - (480 - 297)));
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

    static cocos2d::Sprite * CreateHitOnce(const cocos2d::Vec2 & pos)
    {
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

    static cocos2d::Sprite * CreateExplosionOnce(const cocos2d::Vec2 & pos)
    {
        auto spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();
        auto animationCache = cocos2d::AnimationCache::getInstance();
        auto explosion = animationCache->getAnimation("EXPLOSION");
        auto explode = cocos2d::Animate::create(explosion);
        auto action = cocos2d::Sequence::create(explode, cocos2d::RemoveSelf::create(), nullptr);
        auto explodeSprite = cocos2d::Sprite::createWithSpriteFrame(spriteFrameCache->getSpriteFrameByName("explode1.png"));
        explodeSprite->runAction(action);
        explodeSprite->setBlendFunc(cocos2d::BlendFunc::ADDITIVE);
        explodeSprite->setPosition(pos);
        return explodeSprite;
    }
};

#endif /* Effect_h */
