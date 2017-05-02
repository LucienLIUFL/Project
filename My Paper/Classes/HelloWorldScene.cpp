#include <functional>
#include "HelloWorldScene.h"
#include "Background.hpp"

#include "Resource.hpp"
#include "Effect.hpp"
#include "Track.hpp"
#include "ContactLogic.hpp"
#include "TouchLogic.hpp"

cocos2d::Scene * HelloWorld::createScene()
{
    cocos2d::Scene * scene = cocos2d::Scene::createWithPhysics();
//    scene->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(cocos2d::Vec2::ZERO);

//     BackGround
    Background * background = Background::create();
    background->scheduleUpdate();
    scene->addChild(background);
//     ~BackGround

    scene->addChild(HelloWorld::create());
    return scene;
}

bool HelloWorld::init()
{
    cocos2d::Layer::init();
    Resource::Load();
    auto vs = cocos2d::Director::getInstance()->getVisibleSize();
    this->Player = Fighter::Create(cocos2d::Point(vs.width * 0.5, vs.height * 0.2));
    this->ScoreLabel = cocos2d::Label::create();
    this->YourBlood = cocos2d::Label::create();

    // Event Lisentener
    auto contactLogic = cocos2d::EventListenerPhysicsContact::create();
    auto playerListener = cocos2d::EventListenerTouchOneByOne::create();

    contactLogic->onContactBegin = std::bind(ContactLogic::ContactDetect, std::placeholders::_1, this, &this->Score);
    playerListener->onTouchBegan = std::bind(TouchLogic::OnTouchBegan, std::placeholders::_1, std::placeholders::_2);
    playerListener->onTouchMoved = std::bind(TouchLogic::OnTouchMoved, std::placeholders::_1, std::placeholders::_2);

    auto eventDispatcher = cocos2d::Director::getInstance()->getEventDispatcher();

    eventDispatcher->addEventListenerWithSceneGraphPriority(contactLogic, this);
    eventDispatcher->addEventListenerWithSceneGraphPriority(playerListener, this->Player);
    // ~Event Lisentener

    this->ScoreLabel->setString("Your Score : ");
    this->ScoreLabel->setPosition(cocos2d::Point(vs.width * 0.8, vs.height * 0.96));
    this->YourBlood->setString("Your Life : ");
    this->YourBlood->setPosition(cocos2d::Point(vs.width * 0.15, vs.height * 0.96));

    this->addChild(this->ScoreLabel);
    this->addChild(this->YourBlood);
    this->addChild(this->Player);
    return true;
}


void HelloWorld::onEnter()
{
    cocos2d::Node::onEnter();

    this->scheduleUpdate();
}


void HelloWorld::update(float delta)
{
    cocos2d::Node::update(delta);

    this->Counter = (this->Counter >= 299) ? 0 : (this->Counter + 1);

    if ((this->Counter % 10) == 0)
    {
        this->Player->Shoot();
    }

    if ((this->Counter % 30) == 0)
    {
        auto enemy = EnemyFighter::Create(cocos2d::Point::ZERO, (cocos2d::random() % 6));
        enemy->runAction(Track::Create((cocos2d::random() % 5), enemy));
        this->addChild(enemy);
    }

    this->ScoreLabel->setString("Your Score : " + Resource::ToString(this->Score));
    this->YourBlood->setString("Your Life : " + Resource::ToString(this->Player->GetHP()));
}


