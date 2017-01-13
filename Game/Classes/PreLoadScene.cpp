#include <string>
#include "ui/CocosGUI.h"

#include "GameMain.h"
#include "SimpleAudioEngine.h"
#include "PreLoadScene.h"

bool PreLoadScene::init() {
    if (!cocos2d::Layer::init()) {
        return false;
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Sprite * barSprite = cocos2d::Sprite::create("res/loadingbar.png");

    this->progress = cocos2d::ProgressTimer::create(barSprite);
    this->progress->setPercentage(0.0f);
    this->progress->setScale(1.0f);
    this->progress->setMidpoint(cocos2d::Vec2(0.0f, 0.5f));
    this->progress->setBarChangeRate(cocos2d::Vec2(1.0f, 0.0f));
    this->progress->setType(cocos2d::ProgressTimer::Type::BAR);
    this->progress->setPosition(visibleSize.width / 2.0f, visibleSize.height / 2.0f);
    this->addChild(this->progress);
    return true;
}

void PreLoadScene::onEnterTransitionDidFinish() {
    cocos2d::Layer::onEnterTransitionDidFinish();
    this->loadMusic("res/s3.wav");
    this->loadEffect("res/b0.mp3");
    this->loadSpriteSheets("res/airfightSheet.plist");

    cocos2d::DelayTime * delay = cocos2d::DelayTime::create(1.1f);

    cocos2d::CallFunc * loadProgressBar = cocos2d::CallFunc::create([this](){
        cocos2d::ProgressFromTo * pft = cocos2d::ProgressFromTo::create(1.0f, 0, 100);
        this->progress->runAction(pft);
    });

    cocos2d::CallFunc * loadStart = cocos2d::CallFunc::create([this]()->void {
            cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
            cocos2d::ui::Button * start = cocos2d::ui::Button::create("res/button.png");
            start->setScale(2);
            start->setPosition(cocos2d::Vec2(visibleSize.width / 2.0f, visibleSize.height * 0.2f));
            start->setTitleText(std::string("Start"));
            start->setTitleFontSize(12);
            start->addTouchEventListener([](cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType type) {
                cocos2d::TransitionSlideInL * transition = cocos2d::TransitionSlideInL::create(0.2f, GameMain::createScene());
                cocos2d::Director::getInstance()->replaceScene(transition);
            });
            this->addChild(start);
    });
    this->runAction(cocos2d::Sequence::create(loadProgressBar, delay, loadStart, nullptr));
}

cocos2d::Scene * PreLoadScene::createScene() {
    cocos2d::Scene * scene = cocos2d::Scene::create();
    scene->addChild(PreLoadScene::create());
    return scene;
}

void PreLoadScene::loadMusic(const std::string & filename) {
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(filename.c_str());
}

void PreLoadScene::loadEffect(const std::string & filename) {
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(filename.c_str());
}

void PreLoadScene::loadSpriteSheets(const std::string & filename) {
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile(filename.c_str());
}

