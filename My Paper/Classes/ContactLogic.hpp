//
//  ContactLogic.hpp
//  Learn
//
//  Created by maples on 4/28/17.
//
//

#ifndef ContactLogic_h
#define ContactLogic_h

#include "Model.hpp"
#include "Effect.hpp"
#include "GameOverScene.hpp"

class ContactLogic
{

public:
    static bool ContactDetect(cocos2d::PhysicsContact & contact, cocos2d::Layer * layer, int * score)
    {
        cocos2d::Node * nodeA = contact.getShapeA()->getBody()->getNode();
        cocos2d::Node * nodeB = contact.getShapeB()->getBody()->getNode();

        if (nodeA && nodeB)
        {
            int maskA = nodeA->getPhysicsBody()->getContactTestBitmask();
            int maskB = nodeB->getPhysicsBody()->getContactTestBitmask();

            switch (maskA | maskB)
            {
                case 0b0101 :
                {
                    // EnemyFighter with Fighter
                    Fighter * fighter = ((maskA == 0b0100) ? (Fighter *)nodeA : (Fighter *)nodeB);
                    EnemyFighter * enemy = ((maskA == 0b0001) ? (EnemyFighter *)nodeA : (EnemyFighter *)nodeB);
                    FighterWithEnemy(fighter, enemy, score);
                    break;
                }
                case 0b0110 :
                {
                    // EnemyBullet with Fighter
                    Fighter * fighter;
                    EnemyBullet * bullet;
                    if (maskA == 0b0100)
                    {
                        fighter = dynamic_cast<Fighter *>(nodeA);
                        bullet = dynamic_cast<EnemyBullet *>(nodeB);
                    }
                    else
                    {
                        fighter = dynamic_cast<Fighter *>(nodeB);
                        bullet = dynamic_cast<EnemyBullet *>(nodeA);
                    }

                    FighterWithBullet(fighter, bullet, score);
                    break;
                }
                case 0b1001 :
                {
                    // Bullet with EnemyFighter
                    EnemyFighter * enemy = ((maskA == 0b0001) ? (EnemyFighter *)nodeA : (EnemyFighter *)nodeB);
                    Bullet * bullet = ((maskA == 0b1000) ? (Bullet *)nodeA : (Bullet *)nodeB);
                    EnemyWithBullet(enemy, bullet, layer, score);
                    break;
                }
                    
                default:
                    break;
            }
        }
        return false;
    }
private:

    static void FighterWithEnemy(Fighter * fighter, EnemyFighter * enemy, const int * score)
    {
        auto layer = fighter->getParent();

        enemy->stopAllActions();
        layer->addChild(Effect::CreateExplosionOnce(enemy->getPosition()));
        layer->removeChild(enemy);
        layer->unscheduleUpdate();

        fighter->Hurt();


        if (!fighter->Alive())
        {
            fighter->stopAllActions();
            layer->addChild(Effect::CreateExplosionOnce(fighter->getPosition()));
            layer->removeChild(fighter);
            layer->unscheduleUpdate();

            auto delay = cocos2d::DelayTime::create(2.0);
            auto transition = cocos2d::CallFunc::create([score]{
                int s = *score;
                auto t = cocos2d::TransitionFade::create(2.0, GameOverScene::CreateScene(s));
                cocos2d::Director::getInstance()->replaceScene(t);
            });
            layer->runAction(cocos2d::Sequence::create(delay, transition, nullptr));
        }
    }

    static void FighterWithBullet(Fighter * fighter, EnemyBullet * bullet, const int * score)
    {
        auto layer = fighter->getParent();

        bullet->stopAllActions();
        layer->addChild(Effect::CreateHitOnce(bullet->getPosition()));
        layer->removeChild(bullet);
        fighter->Hurt();

        if (!fighter->Alive())
        {
            fighter->stopAllActions();
            layer->addChild(Effect::CreateExplosionOnce(fighter->getPosition()));
            layer->removeChild(fighter);
            layer->unscheduleUpdate();

            auto delay = cocos2d::DelayTime::create(2.0);
            auto transition = cocos2d::CallFunc::create([score]
            {
                int s = *score;
                auto t = cocos2d::TransitionFade::create(2.0, GameOverScene::CreateScene(s));
                cocos2d::Director::getInstance()->replaceScene(t);
            });
            layer->runAction(cocos2d::Sequence::create(delay, transition, nullptr));
        }

    }

    static void EnemyWithBullet(EnemyFighter * enemy, Bullet * bullet, cocos2d::Layer * layer, int * score)
    {
        bullet->stopAllActions();

        layer->addChild(Effect::CreateHitOnce(bullet->getPosition()));
        layer->removeChild(bullet);
        enemy->Hurt();

        if (!enemy->Alive())
        {
            enemy->stopAllActions();

            layer->addChild(Effect::CreateExplosionOnce(enemy->getPosition()));
            layer->removeChild(enemy);
            ++(*score);
        }
    }
};


#endif /* ContactLogic_h */
