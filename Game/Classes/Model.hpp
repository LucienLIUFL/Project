//
//  Model.hpp
//  Learn
//
//  Created by maples on 4/27/17.
//
//

#ifndef Model_HPP
#define Model_HPP

#include "cocos2d.h"

class EnemyBullet : public cocos2d::Sprite {
public:
    static EnemyBullet * Create(const cocos2d::Vec2 & pos) {
        auto vs = cocos2d::Director::getInstance()->getVisibleSize();
        auto sfc = cocos2d::SpriteFrameCache::getInstance();
        EnemyBullet * e = new EnemyBullet();
        if (e && e->initWithSpriteFrame(sfc->getSpriteFrameByName("W2.png"))) {
            auto move = cocos2d::MoveBy::create(3.0, cocos2d::Vec2(0, -vs.height));
            auto action = cocos2d::Sequence::create(move, cocos2d::RemoveSelf::create(), nullptr);
            e->autorelease();
            e->setPhysicsBody(cocos2d::PhysicsBody::createBox(e->getContentSize()));
            e->getPhysicsBody()->setContactTestBitmask(0b0010);
            e->setBlendFunc(cocos2d::BlendFunc::ADDITIVE);
            e->setPosition(pos);
            e->runAction(action);
            return e;
        }
        CC_SAFE_DELETE(e);
        return nullptr;
    }
};

class Bullet : public cocos2d::Sprite {
public:
    static Bullet * Create(const cocos2d::Vec2 & pos) {
        auto sfc = cocos2d::SpriteFrameCache::getInstance();
        auto vs = cocos2d::Director::getInstance()->getVisibleSize();
        Bullet * e = new Bullet();
        if (e && e->initWithSpriteFrame(sfc->getSpriteFrameByName("W1.png"))) {
            auto move = cocos2d::MoveBy::create(0.5, cocos2d::Vec2(0, vs.height));
            auto action = cocos2d::Sequence::create(move, cocos2d::RemoveSelf::create(), nullptr);
            e->autorelease();
            e->setPhysicsBody(cocos2d::PhysicsBody::createBox(e->getContentSize()));
            e->getPhysicsBody()->setContactTestBitmask(0b1000);
            e->setPosition(pos);
            e->setBlendFunc(cocos2d::BlendFunc::ADDITIVE);
            e->runAction(action);
            return e;
        }
        CC_SAFE_DELETE(e);
        return nullptr;
    }
};

class EnemyFighter : public cocos2d::Sprite {
private:
    int hp;
public:
    static EnemyFighter * Create(const cocos2d::Vec2 & pos, int flag) {
        auto sfc = cocos2d::SpriteFrameCache::getInstance();
        std::string name("E");
        name.append(std::to_string(flag));
        name.append(".png");

        int tempHp = 2; // 0 1

        if ((flag > 1) && (flag < 4)) {
            tempHp = 3; // 2 3
        } else if ((flag > 3) && (flag < 6)) {
            tempHp = 4; // 4 5
        }

        EnemyFighter * e = new EnemyFighter();
        if (e && e->initWithSpriteFrame(sfc->getSpriteFrameByName(name))) {
            e->autorelease();
            e->setPhysicsBody(cocos2d::PhysicsBody::createBox(e->getContentSize() * 0.7));
            e->getPhysicsBody()->setContactTestBitmask(0b0001);
            e->hp = tempHp;
            e->setPosition(pos);
            return e;
        }
        CC_SAFE_DELETE(e);
        return nullptr;
    }


    bool Alive() {
        return (this->hp > 0);
    }

    void Hurt() {
        --this->hp;
    }

    void Shoot() {
        auto pos = this->getPosition();
        auto bullet = EnemyBullet::Create(cocos2d::Vec2(pos.x, pos.y - 30));
        this->getParent()->addChild(bullet);
    }
};

class Fighter : public cocos2d::Sprite {
private:
    int hp = 3;

public:

    bool Alive() {
        return (this->hp > 0);
    }

    void Hurt() {
        --this->hp;
    }

    void Shoot() {
        auto pos = this->getPosition();

        auto bullet0 = Bullet::Create(cocos2d::Vec2(pos.x + 12, pos.y + 42));
        auto bullet1 = Bullet::Create(cocos2d::Vec2(pos.x - 12, pos.y + 42));
        this->getParent()->addChild(bullet0);
        this->getParent()->addChild(bullet1);
    }

    static Fighter * Create(const cocos2d::Vec2 & pos) {
        auto sfc = cocos2d::SpriteFrameCache::getInstance();
        auto ac = cocos2d::AnimationCache::getInstance();
        Fighter * fighter = new Fighter();
        if (fighter && fighter->initWithSpriteFrame(sfc->getSpriteFrameByName("ship03.png"))) {
            fighter->autorelease();

            auto flying = cocos2d::Animate::create(ac->getAnimation("FLY"));
            fighter->setPhysicsBody(cocos2d::PhysicsBody::createBox(fighter->getContentSize() * 0.7));
            fighter->getPhysicsBody()->setContactTestBitmask(0b0100);
            fighter->setPosition(pos);
            fighter->runAction(cocos2d::RepeatForever::create(flying));
            return fighter;
        }

        CC_SAFE_DELETE(fighter);
        return nullptr;
    }
};





#endif /* Model_h */
