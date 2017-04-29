//
//  Background.cpp
//  Learn
//
//  Created by maples on 4/24/17.
//
//

#include "Background.h"
#include "Resource.hpp"

bool Background::init() {
    cocos2d::Layer::init();
    auto spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();

    // BackGround Image
    spriteFrameCache->addSpriteFramesWithFile(Resource::BACK_GROUND_PATH);
    this->images.pushBack(cocos2d::Sprite::createWithSpriteFrame(spriteFrameCache->getSpriteFrameByName("bg01.png")));
    this->images.at(0)->setAnchorPoint(cocos2d::Vec2::ZERO);
    this->images.at(0)->getTexture()->setAliasTexParameters();

    this->images.pushBack(cocos2d::Sprite::createWithSpriteFrame(spriteFrameCache->getSpriteFrameByName("bg01.png")));
    this->images.at(1)->setAnchorPoint(cocos2d::Vec2::ZERO);
    this->images.at(1)->getTexture()->setAliasTexParameters();

    float tempFirstBackGround = this->images.at(0)->getContentSize().height;
    this->images.at(1)->setPosition(cocos2d::Vec2(0, tempFirstBackGround));
    // ~BackGround Image

    spriteFrameCache->addSpriteFramesWithFile(Resource::BACK_BUILDS_PATH);

    this->builds.pushBack(cocos2d::Sprite::createWithSpriteFrame(spriteFrameCache->getSpriteFrameByName("lvl1_map1.png")));
    this->builds.pushBack(cocos2d::Sprite::createWithSpriteFrame(spriteFrameCache->getSpriteFrameByName("lvl1_map2.png")));
    this->builds.pushBack(cocos2d::Sprite::createWithSpriteFrame(spriteFrameCache->getSpriteFrameByName("lvl1_map3.png")));
    this->builds.pushBack(cocos2d::Sprite::createWithSpriteFrame(spriteFrameCache->getSpriteFrameByName("lvl1_map4.png")));

    return true;
}

void Background::onEnter() {
    cocos2d::Layer::onEnter();

    this->addChild(this->images.at(0));
    this->addChild(this->images.at(1));

}


void Background::update(float delta) {
    cocos2d::Layer::update(delta);

    auto vs = cocos2d::Director::getInstance()->getVisibleSize();
    auto spawn = cocos2d::Spawn::create(cocos2d::MoveBy::create(2.0, cocos2d::Vec2(0, -(vs.height * 1.2))), nullptr);
    auto action = cocos2d::Sequence::create(spawn, cocos2d::RemoveSelf::create(), nullptr);
    if (this->BuildsFlag > 3) {
        this->BuildsFlag = 0;
    }

    cocos2d::Vec2 pos = this->images.at(0)->getPosition();
    pos.y -= 5.0;
    if (pos.y < -this->images.at(0)->getContentSize().height) {
        pos = cocos2d::Vec2::ZERO;

        auto sprite = this->builds.at(this->BuildsFlag);
        sprite->runAction(action->clone());
        sprite->setPosition(cocos2d::Vec2(vs.width * 0.25 * this->BuildsFlag, vs.height * 1.1));

        this->addChild(sprite);
    }
    this->images.at(0)->setPosition(pos);


    pos = this->images.at(1)->getPosition();
    pos.y -= 5.0;
    if (pos.y < 0) {
        pos.y = this->images.at(1)->getContentSize().height;
        this->BuildsFlag++;
    }
    this->images.at(1)->setPosition(pos);

}