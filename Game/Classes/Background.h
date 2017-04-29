//
//  Background.hpp
//  Learn
//
//  Created by maples on 4/24/17.
//
//

#ifndef Background_h
#define Background_h

#include "cocos2d.h"

class Background : public cocos2d::Layer {
public:
    CREATE_FUNC(Background);
    virtual bool init() override;
    virtual void update(float delta) override;
    virtual void onEnter() override;
private:
    cocos2d::Vector<cocos2d::Sprite *> images;
    cocos2d::Vector<cocos2d::Sprite *> builds;

    int BuildsFlag = 0;
};
#endif /* Background_hpp */
