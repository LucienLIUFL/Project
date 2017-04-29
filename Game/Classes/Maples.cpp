#include <iostream>
#include "Maples.h"

cocos2d::Animation * Maples::createAnimation(const std::string & filename, int num, double delay) {
    cocos2d::SpriteFrame * spriteFrame;
    cocos2d::Animation * animation = cocos2d::Animation::create();
    cocos2d::SpriteFrameCache * spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();

    // Fetch sprite frames form sprite frame cache and append them to animation
    for (int i = 0; i < num; i++) {
        spriteFrame = spriteFrameCache->getSpriteFrameByName(filename + toString(i + 1) + ".png");
        animation->addSpriteFrame(spriteFrame);
    }

    // Set the Animation Interval
    animation->setDelayPerUnit(static_cast<float>(delay));

    // Set ture to make animation back to first frame after done
    animation->setRestoreOriginalFrame(true);
    return animation;
}

cocos2d::Sprite * Maples::createSprite() {
    // 1st Step: Read plist file and add it to spirteFrameCache
    cocos2d::SpriteFrameCache * spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();
    spriteFrameCache->addSpriteFramesWithFile("pnglist/hero.plist");

    // 2nd Step: Create Animation and use it to create Animate(inherit form Action)
    cocos2d::Animation * animation = createAnimation("run", 12, 0.05);
    cocos2d::Animate * animate = cocos2d::Animate::create(animation);

    // 3rd Step: use the first frame of animation to create a sprite
    cocos2d::SpriteFrame * spriteFrame = spriteFrameCache->getSpriteFrameByName("run1.png");
    cocos2d::Sprite * sprite = cocos2d::Sprite::createWithSpriteFrame(spriteFrame);
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    sprite->setPosition(cocos2d::Vec2(visibleSize.width/2.0f, visibleSize.height/2.0f));
    sprite->setScale(0.3f);

    // 4th Step: run the animate with sprite
    cocos2d::RepeatForever * repeatForever = cocos2d::RepeatForever::create(animate);
    sprite->runAction(repeatForever);
    return sprite;
}

//bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event) {
//    cocos2d::Node * target = event->getCurrentTarget();
//    cocos2d::Vec2 targetPosition = target->getPosition();
//    cocos2d::Vec2 touchPosition = touch->getLocation();
//    cocos2d::log("%f, %f", targetPosition.x, targetPosition.y);
//    return true;
//}
//
//void onTouchCallback(cocos2d::Touch * touch, cocos2d::Event * event) {
//    cocos2d::Node * target = event->getCurrentTarget();
//    cocos2d::Vec2 newPosition = target->getPosition() + touch->getDelta();
//    target->setPosition(newPosition);
//}
//
//void Maples::createEvent() {
//    cocos2d::Director * director = cocos2d::Director::getInstance();
//    cocos2d::EventDispatcher * eventDispatcher = director->getEventDispatcher();
//
//    cocos2d::EventListenerTouchOneByOne * singleTouch = cocos2d::EventListenerTouchOneByOne::create();
//    singleTouch->onTouchBegan = std::bind(onTouchBegan, std::placeholders::_1, std::placeholders::_2);
//    singleTouch->onTouchMoved = std::bind(onTouchCallback, std::placeholders::_1, std::placeholders::_2);
//
//    cocos2d::Sprite * hero = createSprite();
//    eventDispatcher->addEventListenerWithSceneGraphPriority(singleTouch, hero);
//}
//
//void Maples::debug(cocos2d::Layer * layer) {
//
//}
//
//void Maples::init(cocos2d::Layer * layer) {
//    auto spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();
//    spriteFrameCache->addSpriteFramesWithFile("res/airfightSheet.plist");
//
//    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
//    auto physicsBody = cocos2d::PhysicsBody::createEdgeBox(
//            visibleSize, cocos2d::PHYSICSBODY_MATERIAL_DEFAULT, 5.0f
//    );
//
//    cocos2d::Node * edgeNode = cocos2d::Node::create();
//    edgeNode->setPosition(cocos2d::Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
//    edgeNode->setPhysicsBody(physicsBody);
//
//    layer->addChild(edgeNode);
//}





