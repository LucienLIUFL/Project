#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "Model.hpp"

class HelloWorld : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    CREATE_FUNC(HelloWorld);

    virtual bool init() override;
    virtual void onEnter() override;

    virtual void update(float delta) override;

private:
    unsigned int counter = 0;
    Fighter * player;
};

#endif // __HELLOWORLD_SCENE_H__
