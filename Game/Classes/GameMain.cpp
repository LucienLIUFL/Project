#include <string>

#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
#include "GameMain.h"

#include "../Controller/Maples.h"


bool GameMain::init() {
    if (!cocos2d::Layer::init()) {
        return false;
    }
    
    this->visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    std::function<cocos2d::Animation * (const std::string &, double, int)> createAnimation(
            [](const std::string & name, double delay, int num) -> cocos2d::Animation * {
                cocos2d::Animation * animation = cocos2d::Animation::create();
                for (int i = 0; i < num; ++i) {

                    std::string tempName = name + Maples::to_string(i) + ".png";
                    animation->addSpriteFrame(
                            cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(tempName)
                    );
                }
                animation->setDelayPerUnit(static_cast<float>(delay));
                animation->setRestoreOriginalFrame(true);
                return animation;
            }
    );

    cocos2d::AnimationCache::getInstance()->addAnimation(createAnimation("plane", 0.08, 2), "plane");
    cocos2d::AnimationCache::getInstance()->addAnimation(createAnimation("blast", 0.09, 4), "blast");
    cocos2d::AnimationCache::getInstance()->addAnimation(createAnimation("bomb", 0.1, 4), "bomb");

    return true;
}

cocos2d::Scene * GameMain::createScene() {
    cocos2d::Scene * scene = cocos2d::Scene::create();
    cocos2d::Layer * layer = GameMain::create();
    scene->addChild(layer);
    return scene;
}

void GameMain::onEnter() {
    cocos2d::Layer::onEnter();

    this->backgroundImage.pushBack(cocos2d::Sprite::create("res/bg1.png"));
    this->backgroundImage.at(0)->setAnchorPoint(cocos2d::Vec2::ZERO);
    this->backgroundImage.at(0)->getTexture()->setAliasTexParameters();
    this->addChild(this->backgroundImage.at(0));

    this->backgroundImage.pushBack(cocos2d::Sprite::create("res/bg1.png"));
    this->backgroundImage.at(1)->setAnchorPoint(cocos2d::Vec2::ZERO);
    this->backgroundImage.at(1)->getTexture()->setAliasTexParameters();
    float tempFirstBackGround = this->backgroundImage.at(0)->getContentSize().height;
    this->backgroundImage.at(1)->setPosition(cocos2d::Vec2(0, tempFirstBackGround));
    this->addChild(this->backgroundImage.at(1));

    this->player = cocos2d::Sprite::createWithSpriteFrameName("plane0.png");
    this->player->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height * 0.1f));
    this->addChild(this->player);

    cocos2d::Animation * playerAnimation = cocos2d::AnimationCache::getInstance()->getAnimation("plane");
    cocos2d::Animate * animate = cocos2d::Animate::create(playerAnimation);
    this->player->runAction(cocos2d::RepeatForever::create(animate));

    this->scoreValue = 0;
    this->scoreLabel = cocos2d::Label::createWithSystemFont(Maples::to_string(this->scoreValue), "arial.ttf", 32);
    this->scoreLabel->setPosition(cocos2d::Vec2(50, visibleSize.height * 0.94f));
    this->addChild(this->scoreLabel);

    cocos2d::EventListenerTouchOneByOne * planeListener = cocos2d::EventListenerTouchOneByOne::create();
    planeListener->onTouchBegan = [](cocos2d::Touch * touch, cocos2d::Event * event) -> bool {
        cocos2d::Node * target = event->getCurrentTarget();
        cocos2d::Vec2 touchLocation = touch->getLocation();
        cocos2d::Vec2 locationInNode = target->convertToNodeSpace(touchLocation);
        cocos2d::Size size = target->getContentSize();
        cocos2d::Rect rect = cocos2d::Rect(0, 0, size.width, size.height);
        return rect.containsPoint(locationInNode);
    }; 
    planeListener->onTouchMoved = [](cocos2d::Touch * touch, cocos2d::Event * event) {
        cocos2d::Node * target =  event->getCurrentTarget();
        target->setPosition(target->getPosition() + touch->getDelta());
    };
    cocos2d::Director::getInstance()->getEventDispatcher()
            ->addEventListenerWithSceneGraphPriority(planeListener, this->player);

    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("res/s3.wav", true);
    this->counter = 0;

    this->scheduleUpdate();
}

void GameMain::update(float delta) {
    cocos2d::Node::update(delta);

    if (++this->counter > 240) {
        this->counter = 0;
    }
    this->updateBackground();
    this->updateBullets();
    this->updateEnemies();
    this->updateScore();
    this->collisionDetection();
}

void GameMain::updateBackground() {
    cocos2d::Vec2 backgroundImagePosition = this->backgroundImage.at(0)->getPosition();
    backgroundImagePosition.y -= 5.0;
    if (backgroundImagePosition.y < -this->backgroundImage.at(0)->getContentSize().height) {
        backgroundImagePosition = cocos2d::Vec2::ZERO;
    }
    this->backgroundImage.at(0)->setPosition(backgroundImagePosition);

    backgroundImagePosition = this->backgroundImage.at(1)->getPosition();
    backgroundImagePosition.y -= 5.0;
    if (backgroundImagePosition.y < 0) {
        backgroundImagePosition.y = this->backgroundImage.at(1)->getContentSize().height;
    }
    this->backgroundImage.at(1)->setPosition(backgroundImagePosition);
}

void GameMain::updateBullets() {
    if (this->counter % 8 == 0) {
        cocos2d::Vec2 position = this->player->getPosition();
        cocos2d::Sprite * bullet = cocos2d::Sprite::createWithSpriteFrameName("bullet.png");
        bullet->setPosition(position);

        float distance = this->visibleSize.height - bullet->getPosition().y + 10;
        cocos2d::MoveBy * moveBy = cocos2d::MoveBy::create(0.4f, cocos2d::Vec2(0, distance));
        bullet->runAction(moveBy);

        this->addChild(bullet);
        this->bullets.pushBack(bullet);
    }

    for (cocos2d::Sprite * iter : this->bullets) {
        if (iter->getPosition().y >= this->visibleSize.height) {
            this->removeChild(iter, true);
            this->bullets.eraseObject(iter);
        }
    }
}

void GameMain::updateEnemies() {
    if (this->counter % 20 == 0) {
        this->addAircraft("e0.png", 0.5f, 1, 2.0f);
        this->addAircraft("e2.png", 0.6f, 2, 3.0f);
    }

    if (this->counter % 100 == 0) {
        this->addAircraft("e1.png", 0.7f, 5, 5.0f);
    }

    for (Aircraft * iter : this->enemies) {
        if (iter->getPosition().y <= 0) {
            this->removeChild(iter);
            this->enemies.eraseObject(iter);
        }
    }
}

void GameMain::updateScore() {
    this->scoreLabel->setString(Maples::to_string(this->scoreValue));
}

void GameMain::collisionDetection() {
    // TODO:
    bool isCollision;
    for (Aircraft * aircraft : this->enemies) {
        // Player and enemy
        if (this->player->getBoundingBox().intersectsRect(aircraft->getBoundingBox())) {
            this->playBombAnimate("blast", aircraft->getPosition());
            this->playBombAnimate("blast", this->player->getPosition());
            aircraft->stopAllActions();
            this->player->stopAllActions();
            this->enemies.eraseObject(aircraft);
            this->removeChild(aircraft);
            this->removeChild(this->player);
            this->over();
            break;
        }

        for (cocos2d::Sprite * bullet : this->bullets) {
            isCollision = bullet->getBoundingBox().intersectsRect(aircraft->getBoundingBox());
            if (isCollision) {
                aircraft->setHealthPoints(aircraft->getHealthPoints() - 1);
                this->playBombAnimate("blast", aircraft->getPosition());
                bullet->stopAllActions();
                this->removeChild(bullet);
                this->bullets.eraseObject(bullet);
                break;
            }
        }

        if (aircraft->getHealthPoints() <= 0) {
            aircraft->stopAllActions();
            this->removeChild(aircraft);
            this->enemies.eraseObject(aircraft);
            this->scoreValue++;
            break;
        }
    }
}

void GameMain::playBombAnimate(const std::string & name, cocos2d::Vec2 position) {
    cocos2d::Animation * animation = cocos2d::AnimationCache::getInstance()->getAnimation(name);
    cocos2d::Sprite * tempSprite = cocos2d::Sprite::createWithSpriteFrameName(name + "0.png");
    tempSprite->setPosition(position);

    cocos2d::Animate * animate = cocos2d::Animate::create(animation);
    cocos2d::CallFunc * remove = cocos2d::CallFunc::create([tempSprite, this]() {
        this->removeChild(tempSprite);
    });
    cocos2d::Sequence * actions = cocos2d::Sequence::create(animate, remove, nullptr);
    tempSprite->runAction(actions);
    this->addChild(tempSprite);
}

void GameMain::over() {
    this->unscheduleUpdate();
//    this->removeAllChildren();
    cocos2d::CallFunc * action = cocos2d::CallFunc::create([this]() {
        CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
        cocos2d::ui::Button * start = cocos2d::ui::Button::create("res/button.png");
        start->setScale(2);
        start->setPosition(cocos2d::Vec2(visibleSize.width / 2.0f, visibleSize.height * 0.2f));
        start->setTitleText(std::string("Retart"));
        start->setTitleFontSize(12);
        start->addTouchEventListener([](cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType type) {
            cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(0.2f, GameMain::createScene()));
        });
        this->addChild(start);

        cocos2d::ui::Button * returnButton = cocos2d::ui::Button::create("res/button.png");
        returnButton->setScale(2);
        returnButton->setPosition(cocos2d::Vec2(visibleSize.width / 2.0f, visibleSize.height * 0.4f));
        returnButton->setTitleText(std::string("Return"));
        returnButton->setTitleFontSize(12);
        returnButton->addTouchEventListener([](cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType type) {
            cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(0.2f, HelloWorld::createScene()));
        });
        this->addChild(returnButton);
    });

    cocos2d::DelayTime * delayTime = cocos2d::DelayTime::create(2.0);
    this->runAction(cocos2d::Sequence::create(delayTime, action, nullptr));
}

void GameMain::addAircraft(const std::string & name, float scale, int healthPoints, float delay) {
    Aircraft * aircraft = Aircraft::createAircraft(name);
    aircraft->setScale(scale);
    aircraft->setHealthPoints(healthPoints);
    aircraft->setPosition(cocos2d::Vec2(cocos2d::random() % (int)visibleSize.width, visibleSize.height));

    cocos2d::MoveBy * moveBy = cocos2d::MoveBy::create(delay, cocos2d::Vec2(0, -visibleSize.height - 100));
    aircraft->runAction(moveBy);

    this->addChild(aircraft);
    this->enemies.pushBack(aircraft);
}


