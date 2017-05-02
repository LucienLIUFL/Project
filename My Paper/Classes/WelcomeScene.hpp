//
//  WelcomeScene.hpp
//  Learn
//
//  Created by maples on 4/30/17.
//
//

#ifndef WelcomeScene_hpp
#define WelcomeScene_hpp

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Resource.hpp"
#include "Effect.hpp"
#include "Model.hpp"
#include "HelloWorldScene.h"
#include "GameOverScene.hpp"

class WelcomeScene : public cocos2d::Layer
{
private:
    Fighter * player;
    int count = 0;
public:
    CREATE_FUNC(WelcomeScene);
    virtual bool init() override
    {
        this->Layer::init();
        Resource::Load();

        auto director = cocos2d::Director::getInstance();
        auto visibleSize = director->getVisibleSize();
        auto background = cocos2d::Sprite::create(Resource::WELCOME_BACKGROUND);
        auto newGame = cocos2d::ui::Button::create(Resource::BUTTON_NEWGAME);
        auto logoMaples = cocos2d::Sprite::create(Resource::LOGO_MAPLE);

        this->player = Fighter::Create(cocos2d::Point(visibleSize.width * 0.2, visibleSize.height * 0.2));

        logoMaples->setPosition(cocos2d::Point(visibleSize.width * 0.5, visibleSize.height * 0.7));
        logoMaples->setBlendFunc(cocos2d::BlendFunc::ADDITIVE);

        background->setPosition(cocos2d::Point::ZERO);
        background->setAnchorPoint(cocos2d::Point::ZERO);

        newGame->setPosition(cocos2d::Point(visibleSize.width * 0.5, visibleSize.height * 0.5));
        newGame->addTouchEventListener([this, director](cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType type){
            if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
            {

                auto stepOne = cocos2d::CallFunc::create([this]
                {
                    this->addChild(Effect::CreateFlare());
                });

                auto stepTwo = cocos2d::CallFunc::create([director]
                {
                    auto transition = cocos2d::TransitionFade::create(2.0, HelloWorld::createScene());
                    director->replaceScene(transition);
                });

                this->runAction(cocos2d::Sequence::create(stepOne, stepTwo, nullptr));

            }
        });

        auto moveToRight = cocos2d::MoveTo::create(2.0, cocos2d::Vec2(visibleSize.width * 0.2, visibleSize.height * 0.2));
        auto moveToLeft = cocos2d::MoveTo::create(2.0, cocos2d::Vec2(visibleSize.width * 0.8, visibleSize.height * 0.2));

        auto sequence = cocos2d::Sequence::create(moveToLeft, moveToRight, nullptr);
        auto playerAction = cocos2d::RepeatForever::create(sequence);

        this->player->runAction(playerAction);

        auto name = cocos2d::Label::create();
        name->setString("姓名 : 刘枫林 (Maples)");
        name->setPosition(cocos2d::Point(visibleSize.width * 0.5, visibleSize.height * 0.36));
        auto info = cocos2d::Label::create();
        info->setString("学号 : 2013060109005");
        info->setPosition(cocos2d::Point(visibleSize.width * 0.5, visibleSize.height * 0.3));

        this->addChild(background);
        this->addChild(this->player);
        this->addChild(logoMaples);
        this->addChild(newGame);
        this->addChild(name);
        this->addChild(info);


        this->scheduleUpdate();
        return true;
    }

    virtual void update(float delta) override
    {
        this->count = (this->count < 300) ? this->count + 1 : 0;

        if ((this->count % 10) == 0)
        {
            this->player->Shoot();
        }
    }

    static cocos2d::Scene * CreateScene()
    {
        cocos2d::Scene * scene = cocos2d::Scene::createWithPhysics();
        scene->getPhysicsWorld()->setGravity(cocos2d::Vec2::ZERO);
        scene->addChild(WelcomeScene::create());
        return scene;
    }
};

#endif /* WelcomeScene_hpp */
