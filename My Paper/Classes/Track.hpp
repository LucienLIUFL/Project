//
//  Track.hpp
//  Learn
//
//  Created by maples on 4/28/17.
//
//

#ifndef Track_h
#define Track_h

#include "cocos2d.h"
#include "Model.hpp"

class Track
{
public:
    static cocos2d::Sequence * Create(int flag, EnemyFighter * enemy)
    {
        assert((flag <= 5 && flag >= 0));
        cocos2d::Sequence * sequence;
        switch (flag)
        {
            case 0 :
                sequence = CreateA(enemy);
                break;
            case 1 :
                sequence = CreateB(enemy);
                break;
            case 2 :
                sequence = CreateC(enemy);
                break;
            case 3 :
                sequence = CreateD(enemy);
                break;
            case 4 :
                sequence = CreateE(enemy);
                break;
            case 5 :
                sequence = CreateF(enemy);
                break;
        }
        return sequence;
    }

private:

    static cocos2d::Sequence * CreateA(EnemyFighter * enemy)
    {
        auto vs = cocos2d::Director::getInstance()->getVisibleSize();

        cocos2d::Point begin(-10, vs.height + 10);
        cocos2d::Point first(vs.width - 10, vs.height * 0.75);
        cocos2d::Point second(vs.width * 0.66, vs.height * 0.75);
        cocos2d::Point third(vs.width * 0.33, vs.height * 0.75);
        cocos2d::Point fourth(vs.width * 0.05, vs.height * 0.75);
        cocos2d::Point end(vs.width * 0.5, -10);

        auto shoot = cocos2d::CallFunc::create([enemy] {enemy->Shoot();});

        enemy->setPosition(begin);
        cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
        actions.pushBack(cocos2d::MoveTo::create(0.5, first));
        actions.pushBack(cocos2d::MoveTo::create(0.8, second));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.8, third));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.8, fourth));
        actions.pushBack(cocos2d::MoveTo::create(0.5, end));
        actions.pushBack(cocos2d::RemoveSelf::create());

        return cocos2d::Sequence::create(actions);
    }

    static cocos2d::Sequence * CreateB(EnemyFighter * enemy)
    {
        auto vs = cocos2d::Director::getInstance()->getVisibleSize();

        cocos2d::Point begin(vs.width + 10, vs.height + 10);
        cocos2d::Point first(vs.width * 0.05, vs.height * 0.75);
        cocos2d::Point second(vs.width * 0.33, vs.height * 0.75);
        cocos2d::Point third(vs.width * 0.66, vs.height * 0.75);
        cocos2d::Point fourth(vs.width * 0.95, vs.height * 0.75);
        cocos2d::Point end(vs.width * 0.5, -10);

        auto shoot = cocos2d::CallFunc::create([enemy] {enemy->Shoot();});

        enemy->setPosition(begin);
        cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
        actions.pushBack(cocos2d::MoveTo::create(0.5, first));
        actions.pushBack(cocos2d::MoveTo::create(0.8, second));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.8, third));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.8, fourth));
        actions.pushBack(cocos2d::MoveTo::create(0.5, end));
        actions.pushBack(cocos2d::RemoveSelf::create());
        return cocos2d::Sequence::create(actions);
    }

    static cocos2d::Sequence * CreateC(EnemyFighter * enemy)
    {
        auto vs = cocos2d::Director::getInstance()->getVisibleSize();

        cocos2d::Point begin(-10, vs.height + 10);
        cocos2d::Point first(vs.width * 0.20, vs.height * 0.55);
        cocos2d::Point second(vs.width * 0.33, vs.height * 0.55);
        cocos2d::Point third(vs.width * 0.66, vs.height * 0.55);
        cocos2d::Point fourth(vs.width * 0.90, vs.height * 0.55);
        cocos2d::Point end(vs.width * 0.95, -10);

        auto shoot = cocos2d::CallFunc::create([enemy] {enemy->Shoot();});

        enemy->setPosition(begin);
        cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
        actions.pushBack(cocos2d::MoveTo::create(0.5, first));
        actions.pushBack(cocos2d::MoveTo::create(0.8, second));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.8, third));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.8, fourth));
        actions.pushBack(cocos2d::MoveTo::create(0.5, end));
        actions.pushBack(cocos2d::RemoveSelf::create());
        return cocos2d::Sequence::create(actions);
    }

    static cocos2d::Sequence * CreateD(EnemyFighter * enemy)
    {
        auto vs = cocos2d::Director::getInstance()->getVisibleSize();

        cocos2d::Point begin(vs.width + 10, vs.height + 10);
        cocos2d::Point first(vs.width * 0.80, vs.height * 0.25);
        cocos2d::Point second(vs.width * 0.66, vs.height * 0.55);
        cocos2d::Point third(vs.width * 0.33, vs.height * 0.55);
        cocos2d::Point fourth(vs.width * 0.1, vs.height * 0.55);
        cocos2d::Point end(vs.width * 0.1, -10);

        auto shoot = cocos2d::CallFunc::create([enemy] {enemy->Shoot();});

        enemy->setPosition(begin);
        cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
        actions.pushBack(cocos2d::MoveTo::create(0.5, first));
        actions.pushBack(cocos2d::MoveTo::create(0.8, second));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.8, third));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.8, fourth));
        actions.pushBack(cocos2d::MoveTo::create(0.5, end));
        actions.pushBack(cocos2d::RemoveSelf::create());
        return cocos2d::Sequence::create(actions);
    }

    static cocos2d::Sequence * CreateE(EnemyFighter * enemy)
    {
        auto vs = cocos2d::Director::getInstance()->getVisibleSize();

        cocos2d::Point begin(vs.width * 0.5, vs.height + 10);
        cocos2d::Point first(vs.width * 0.5, vs.height * 0.65);
        cocos2d::Point second(vs.width * 0.1, vs.height * 0.65);
        cocos2d::Point third(vs.width * 0.5, vs.height * 0.65);
        cocos2d::Point fourth(vs.width * 0.9, vs.height * 0.65);
        cocos2d::Point end(vs.width * 0.1, -10);

        auto shoot = cocos2d::CallFunc::create([enemy] {enemy->Shoot();});

        enemy->setPosition(begin);
        cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
        actions.pushBack(cocos2d::MoveTo::create(0.5, first));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.8, second));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.8, third));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.8, fourth));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.5, end));
        actions.pushBack(cocos2d::RemoveSelf::create());
        return cocos2d::Sequence::create(actions);
    }

    static cocos2d::Sequence * CreateF(EnemyFighter * enemy)
    {
        auto vs = cocos2d::Director::getInstance()->getVisibleSize();

        cocos2d::Point begin(-10, -10);
        cocos2d::Point first(vs.width * 0.9, vs.height * 0.85);
        cocos2d::Point second(vs.width * 0.5, vs.height * 0.85);
        cocos2d::Point third(vs.width * 0.3, vs.height * 0.85);
        cocos2d::Point end(vs.width + 10, -10);

        auto shoot = cocos2d::CallFunc::create([enemy] {enemy->Shoot();});

        enemy->setPosition(begin);
        cocos2d::Vector<cocos2d::FiniteTimeAction *> actions;
        actions.pushBack(cocos2d::MoveTo::create(0.5, first));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.8, second));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.8, third));
        actions.pushBack(shoot->clone());
        actions.pushBack(cocos2d::MoveTo::create(0.5, end));
        actions.pushBack(cocos2d::RemoveSelf::create());
        return cocos2d::Sequence::create(actions);
    }
};

#endif /* Track_h */
