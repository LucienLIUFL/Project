#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"

#include "AudioControlScene.h"
#include "HelloWorldScene.h"


bool AudioControlScene::init() {
    if (!cocos2d::Layer::init()) {
        return false;
    }
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    cocos2d::ui::Text * musicText = cocos2d::ui::Text::create("BGMusic", "fonts/arial.ttf", 28);
    musicText->setPosition(cocos2d::Vec2(visibleSize.width * 0.25f, visibleSize.height * 0.7f));
    this->addChild(musicText);

    cocos2d::ui::Slider * musicSlider = cocos2d::ui::Slider::create("res/sliderTrack.png", "res/sliderThumb.png");
    musicSlider->loadProgressBarTexture("res/sliderProgress.png");
    musicSlider->setPercent(100);
    musicSlider->setPosition(cocos2d::Vec2(visibleSize.width * 0.6f, visibleSize.height * 0.7f));
    musicSlider->addEventListener([musicSlider](cocos2d::Ref * pSender, cocos2d::ui::Slider::EventType type) {
        if (type == cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED) {
            float percent = musicSlider->getPercent() / 100.f;
            CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(percent);
        }
    });
    this->addChild(musicSlider);

    // Music Text
    cocos2d::ui::Text * effectText = cocos2d::ui::Text::create("EfMusic", "fonts/arial.ttf", 28);
    effectText->setPosition(cocos2d::Vec2(visibleSize.width * 0.25f, visibleSize.height * 0.5f));
    this->addChild(effectText);

    // Slider
    cocos2d::ui::Slider * effectSlider = cocos2d::ui::Slider::create("res/sliderTrack.png", "res/sliderThumb.png");
    effectSlider->loadProgressBarTexture("res/sliderProgress.png");
    effectSlider->setPercent(100);
    effectSlider->setPosition(cocos2d::Vec2(visibleSize.width * 0.6f, visibleSize.height * 0.5f));
    effectSlider->addEventListener([effectSlider](cocos2d::Ref * pSender, cocos2d::ui::Slider::EventType type) {
        if (type == cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED) {
            float percent = effectSlider->getPercent() / 100.f;
            CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(percent);
        }
    });
    this->addChild(effectSlider);
    //Need Event

    cocos2d::ui::Button * returnButton = cocos2d::ui::Button::create("res/button.png");
    returnButton->setScale(2);
    returnButton->setPosition(cocos2d::Vec2(visibleSize.width / 2.0f, visibleSize.height * 0.2f));
    returnButton->setTitleText("Return");
    returnButton->setTitleFontSize(14);
    returnButton->addTouchEventListener([](cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType type) {
        if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {
            cocos2d::TransitionSlideInL * transition = cocos2d::TransitionSlideInL::create(1.0f, HelloWorld::createScene());
            cocos2d::Director::getInstance()->replaceScene(transition);
        }
    });
    this->addChild(returnButton);
    return true;
}

cocos2d::Scene * AudioControlScene::createScene() {
    cocos2d::Scene * scene = cocos2d::Scene::create();
    scene->addChild(AudioControlScene::create());
    return scene;
}