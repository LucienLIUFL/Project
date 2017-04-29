#ifndef MYGAME_GAMEMAIN_H
#define MYGAME_GAMEMAIN_H
#include <string>

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include "../Model/Aircraft.h"

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

    void update(float delta);
    void updateBackground();
    void updateEnemies();
    void updateBullets();
    void updateScore();
    void collisionDetection();

    void playBombAnimate(const std::string &, cocos2d::Vec2);
    void over();

    void addAircraft(const std::string & name, float scale, int healthPoints, float delay);
};


#endif //MYGAME_GAMEMAIN_H
