#ifndef PRELOADSCENE_H_
#define PRELOADSCENE_H_
#include <string>
#include "cocos2d.h"

class PreLoadScene : public cocos2d::Layer {
public:
    virtual void onEnterTransitionDidFinish();
    virtual bool init();
    static cocos2d::Scene * createScene();
    CREATE_FUNC(PreLoadScene);
protected:
    cocos2d::ProgressTimer * progress;

    // Function
    void loadMusic(const std::string & filename);
    void loadEffect(const std::string & filename);
    void loadSpriteSheets(const std::string & filename);
};

#endif