#include <functional>
#include "HelloWorldScene.h"
#include "Background.h"

#include "Resource.hpp"
#include "Effect.hpp"
#include "Track.hpp"
#include "ContactLogic.hpp"
#include "TouchLogic.hpp"

cocos2d::Scene * HelloWorld::createScene() {
    auto scene = cocos2d::Scene::create();

//    cocos2d::Scene * scene = cocos2d::Scene::createWithPhysics();
//    scene->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);
//    scene->getPhysicsWorld()->setGravity(cocos2d::Vec2::ZERO);

//     BackGround
//    Background * background = Background::create();
//    background->scheduleUpdate();
//    scene->addChild(background);
//     ~BackGround

    scene->addChild(HelloWorld::create());
    return scene;
}

bool HelloWorld::init() {
    cocos2d::Layer::init();
    Resource::Load();
//    auto vs = cocos2d::Director::getInstance()->getVisibleSize();
//    this->player = Fighter::Create(cocos2d::Point(vs.width * 0.5, vs.height * 0.2));
//
//    auto contactLogic = cocos2d::EventListenerPhysicsContact::create();
//    auto playerListener = cocos2d::EventListenerTouchOneByOne::create();
//
//    contactLogic->onContactBegin = std::bind(ContactLogic::ContactDetect, std::placeholders::_1, this);
//    playerListener->onTouchBegan = std::bind(TouchLogic::OnTouchBegan, std::placeholders::_1, std::placeholders::_2);
//    playerListener->onTouchMoved = std::bind(TouchLogic::OnTouchMoved, std::placeholders::_1, std::placeholders::_2);
//
//    auto eventDispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
//
//    eventDispatcher->addEventListenerWithSceneGraphPriority(contactLogic, this);
//    eventDispatcher->addEventListenerWithSceneGraphPriority(playerListener, this->player);
//
//    this->addChild(this->player);
    return true;
}




void HelloWorld::onEnter() {
    cocos2d::Node::onEnter();
//    EnemyFighter * enemy = EnemyFighter::Create(cocos2d::Vec2::ZERO, 0);
//    enemy->runAction(Track::Create(5, enemy));
//    this->addChild(enemy);
//
//
//    this->scheduleUpdate();
}


void HelloWorld::update(float delta) {
    cocos2d::Node::update(delta);
}


