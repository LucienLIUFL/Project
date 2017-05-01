#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Model.hpp"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    CREATE_FUNC(HelloWorld);
    virtual bool init() override;
    virtual void onEnter() override;
    virtual void update(float delta) override;

private:
    unsigned int Counter = 0;
    cocos2d::Label * ScoreLabel;
    cocos2d::Label * YourBlood;
    int Score = 0;
    Fighter * Player;
};

#endif // __HELLOWORLD_SCENE_H__
