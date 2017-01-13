#ifndef MYGAME_GAMEMAIN_H
#define MYGAME_GAMEMAIN_H
#include <string>

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include "Aircraft.h"

class GameMain : public cocos2d::Layer {
public:
    virtual bool init();
    virtual void onEnter();
    static cocos2d::Scene * createScene();
    CREATE_FUNC(GameMain);

private:
    cocos2d::Size visibleSize;
    int counter;

    cocos2d::Sprite * player;
    cocos2d::Vector<cocos2d::Sprite *> backgroundImage;

    cocos2d::Vector<Aircraft *> enemies;
    cocos2d::Vector<cocos2d::Sprite *> bullets;

    cocos2d::Label * scoreLabel;
    int scoreValue;

    Aircraft * boss;
    cocos2d::Vector<cocos2d::Sprite *> bossBullets;
    bool bossIsStart = false;
    bool bossIsMove = false;
    bool bossIsShoot = false;

    void update(float delta);
    void updateBackground();
    void updateEnemies();
    void updateBullets();
    void collisionDetection();

    void playBombAnimate(const std::string &, cocos2d::Vec2);
    void over();
};


#endif //MYGAME_GAMEMAIN_H
