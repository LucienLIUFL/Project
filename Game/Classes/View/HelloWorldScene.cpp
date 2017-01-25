#include <string>
#include "ui/CocosGUI.h"

#include "HelloWorldScene.h"
#include "PreLoadScene.h"
#include "AudioControlScene.h"
#include "SimpleAudioEngine.h"

cocos2d::Scene * HelloWorld::createScene() {
    cocos2d::Scene * scene = cocos2d::Scene::create();
    HelloWorld * layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init() {

    if (!cocos2d::Layer::init()) {
        return false;
    }

    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	// Set Start Button
    cocos2d::ui::Button * startButton = cocos2d::ui::Button::create("res/button.png");
	startButton->setScale(2);
	startButton->setTitleText("Start");
	startButton->setTitleFontSize(14);
	startButton->setTitleFontName("fonts/arial.ttf");
	startButton->setPosition(cocos2d::Vec2(visibleSize.width / 2, (float)(visibleSize.height * 0.7)));
    startButton->addTouchEventListener([](cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType type){
        if (type == cocos2d::ui::Widget::TouchEventType::ENDED){
	 	    cocos2d::TransitionSlideInL * transition = cocos2d::TransitionSlideInL::create(1.0, PreLoadScene::createScene());
	 	    cocos2d::Director::getInstance()->replaceScene(transition);
        }
    });
	this->addChild(startButton);

    cocos2d::ui::Button * setButton = cocos2d::ui::Button::create("res/button.png");
	setButton->setScale(2);
	setButton->setTitleText("Set");
	setButton->setTitleFontSize(14);
	setButton->setTitleFontName("fonts/arial.ttf");
	setButton->setPosition(cocos2d::Vec2(visibleSize.width / 2, (float)(visibleSize.height * 0.55)));
	setButton->addTouchEventListener([](cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType type){
        if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {
            cocos2d::TransitionSlideInL * transition = cocos2d::TransitionSlideInL::create(1.0, AudioControlScene::createScene());
            cocos2d::Director::getInstance()->replaceScene(transition);
        }
    });
	this->addChild(setButton);

    cocos2d::ui::Button * closeButton = cocos2d::ui::Button::create("res/button.png");
	closeButton->setScale(2);
	closeButton->setTitleText("Close");
	closeButton->setTitleFontSize(14);
	closeButton->setTitleFontName("fonts/arial.ttf");
	closeButton->setPosition(cocos2d::Vec2(visibleSize.width / 2, (float)(visibleSize.height * 0.4)));
	closeButton->addTouchEventListener([](cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType type) {
		if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {
            cocos2d::Director::getInstance()->end();
			exit(0);
		}
	});

	this->addChild(closeButton);

	std::string info("Made by Maples");
    cocos2d::ui::Text * bannerText = cocos2d::ui::Text::create(info, "fonts/arial.ttf", 32);
	bannerText->setPosition(cocos2d::Vec2(visibleSize.width / 2, (float)(visibleSize.height * 0.15)));
	this->addChild(bannerText);

    return true;
}
