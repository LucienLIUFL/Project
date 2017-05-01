//
//  GameOverScene.hpp
//  Learn
//
//  Created by maples on 4/30/17.
//
//

#ifndef GameOverScene_h
#define GameOverScene_h

#include "cocos2d.h"
#include "Resource.hpp"
#include "ui/CocosGUI.h"

class GameOverScene : cocos2d::Layer
{
private:
    int Score;

public:
    CREATE_FUNC(GameOverScene);
    virtual bool init() override
    {
        this->Layer::init();

        auto director = cocos2d::Director::getInstance();
        auto visibleSize = director->getVisibleSize();
        auto background = cocos2d::Sprite::create(Resource::WELCOME_BACKGROUND);
        auto playAgain = cocos2d::ui::Button::create(Resource::BUTTON_PLAYAGAIN);
        auto logoGameOver = cocos2d::Sprite::create(Resource::LOGO_GAMEOVER);


        logoGameOver->setPosition(cocos2d::Point(visibleSize.width * 0.5, visibleSize.height * 0.7));
        logoGameOver->setBlendFunc(cocos2d::BlendFunc::ADDITIVE);

        background->setPosition(cocos2d::Point::ZERO);
        background->setAnchorPoint(cocos2d::Point::ZERO);

        playAgain->setPosition(cocos2d::Point(visibleSize.width * 0.5, visibleSize.height * 0.5));
        playAgain->addTouchEventListener([this, director](cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType type){
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


        this->addChild(background);
        this->addChild(logoGameOver);
        this->addChild(playAgain);

        return true;
    }

    virtual void onEnter() override
    {
        cocos2d::Layer::onEnter();
        auto director = cocos2d::Director::getInstance();
        auto visibleSize = director->getVisibleSize();
        auto yourScore = cocos2d::Label::create();
        yourScore->setString(std::string("Your Score : ") + Resource::ToString(this->Score));
        yourScore->setPosition(cocos2d::Point(visibleSize.width * 0.5, visibleSize.height * 0.3));
        yourScore->setScale(2);
        this->addChild(yourScore);
    }

    static cocos2d::Scene * CreateScene(int score)
    {
        GameOverScene * layer = GameOverScene::create();
        layer->Score = score;
        auto scene = cocos2d::Scene::create();
        scene->addChild(layer);
        return scene;
    }
};

#endif /* GameOverScene_h */
