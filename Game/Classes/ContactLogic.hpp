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

class ContactLogic {

public:
    static bool ContactDetect(cocos2d::PhysicsContact & contact, cocos2d::Layer * layer) {
        cocos2d::Node * nodeA = contact.getShapeA()->getBody()->getNode();
        cocos2d::Node * nodeB = contact.getShapeB()->getBody()->getNode();

        int maskA = nodeA->getPhysicsBody()->getContactTestBitmask();
        int maskB = nodeB->getPhysicsBody()->getContactTestBitmask();

        switch (maskA | maskB) {
            case 0b0101 : {// EnemyFighter with Fighter
                Fighter * fighter = ((maskA == 0b0100) ? (Fighter *)nodeA : (Fighter *)nodeB);
                EnemyFighter * enemy = ((maskA == 0b0001) ? (EnemyFighter *)nodeA : (EnemyFighter *)nodeB);
                FighterWithEnemy(fighter, enemy);
                break;
            }
            case 0b0110 : {// EnemyBullet with Fighter
                Fighter * fighter;
                EnemyBullet * bullet;
                if (maskA == 0b0100) {
                    fighter = dynamic_cast<Fighter *>(nodeA);
                    bullet = dynamic_cast<EnemyBullet *>(nodeB);
                } else {
                    fighter = dynamic_cast<Fighter *>(nodeB);
                    bullet = dynamic_cast<EnemyBullet *>(nodeA);
                }

                FighterWithBullet(fighter, bullet);
                break;
            }
            case 0b1001 : {// Bullet with EnemyFighter
                EnemyFighter * enemy = ((maskA == 0b0001) ? (EnemyFighter *)nodeA : (EnemyFighter *)nodeB);
                Bullet * bullet = ((maskA == 0b1000) ? (Bullet *)nodeA : (Bullet *)nodeB);
                EnemyWithBullet(enemy, bullet);
                break;
            }

            default:
                break;
        }

        return false;
    }
private:

    static void FighterWithEnemy(Fighter * fighter, EnemyFighter * enemy) {
        auto layer = fighter->getParent();
        fighter->stopAllActions();
        enemy->stopAllActions();

        layer->addChild(Effect::CreateExplosionOnce(fighter->getPosition()));
        layer->addChild(Effect::CreateExplosionOnce(enemy->getPosition()));

        layer->removeChild(fighter);
        layer->removeChild(enemy);


        // TODO : GAME OVER
        cocos2d::log("TODO : GAME OVER");
    }

    static void FighterWithBullet(Fighter * fighter, EnemyBullet * bullet) {
        auto layer = fighter->getParent();

        bullet->stopAllActions();
        layer->addChild(Effect::CreateHitOnce(bullet->getPosition()));
        layer->removeChild(bullet);
        fighter->Hurt();

        if (!fighter->Alive()) {
            fighter->stopAllActions();
            layer->addChild(Effect::CreateExplosionOnce(fighter->getPosition()));
            layer->removeChild(fighter);
            // TODO : GAME OVER
            cocos2d::log("TODO : GAME OVER");
        }

    }

    static void EnemyWithBullet(EnemyFighter * enemy, Bullet * bullet) {
        auto layer = enemy->getParent();


        bullet->stopAllActions();

        layer->addChild(Effect::CreateHitOnce(bullet->getPosition()));
        layer->removeChild(bullet);
        enemy->Hurt();

        if (!enemy->Alive()) {
            enemy->stopAllActions();
            layer->addChild(Effect::CreateExplosionOnce(enemy->getPosition()));
            layer->removeChild(enemy);
        }
    }
};


#endif /* ContactLogic_h */
