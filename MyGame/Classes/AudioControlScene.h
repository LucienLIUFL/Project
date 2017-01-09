#ifndef MYGAME_AUDIOCONTROLSCENE_H
#define MYGAME_AUDIOCONTROLSCENE_H
#include "cocos2d.h"

class AudioControlScene : cocos2d::Layer {
public:
    virtual bool init();

    static cocos2d::Scene * createScene();
    CREATE_FUNC(AudioControlScene);
};

#endif //MYGAME_AUDIOCONTROLSCENE_H
