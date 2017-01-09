#ifndef MYGAME_GAMEMAIN_H
#define MYGAME_GAMEMAIN_H

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class GameMain : public cocos2d::Layer {
public:
    virtual bool init();

    static cocos2d::Scene * createScene();

private:

};


#endif //MYGAME_GAMEMAIN_H
