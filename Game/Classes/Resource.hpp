//
//  Resource.hpp
//  Learn
//
//  Created by maples on 4/28/17.
//
//

#ifndef Resource_h
#define Resource_h

#include <string>

namespace Resource
{
    const std::string LOGO_MAPLE = "logo.png";
    const std::string LOGO_GAMEOVER = "gameOver.png";
    const std::string BUTTON_PLAYAGAIN = "PlayAgain1.png";
    const std::string BUTTON_NEWGAME = "NewGame1.png";
    const std::string BUTTON_ABOUT = "About1.png";
    const std::string WELCOME_BACKGROUND = "loading.png";
    const std::string BACK_PLANE = "textureTransparentPack.plist";
    const std::string BULLET_HIT_EXPLODE= "textureOpaquePack.plist";
    const std::string EXPLOSION = "explosion.plist";
    const std::string BACK_BUILD = "b01.plist";
    const std::string FLARE = "flare.jpg";
    const std::string BACK_GROUND_PATH = "textureTransparentPack.plist";
    const std::string BACK_BUILDS_PATH = "b01.plist";

    template <class T>
    inline std::string ToString(const T & value) {
        std::ostringstream otm;
        otm << value;
        return otm.str();
    }

    inline bool Load()
    {
        auto spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();
        auto animationCache = cocos2d::AnimationCache::getInstance();

        spriteFrameCache->addSpriteFramesWithFile(BACK_PLANE);
        spriteFrameCache->addSpriteFramesWithFile(BULLET_HIT_EXPLODE);
        spriteFrameCache->addSpriteFramesWithFile(EXPLOSION);
        spriteFrameCache->addSpriteFramesWithFile(BACK_BUILD);


        auto fly = cocos2d::Animation::create();
        fly->addSpriteFrame(spriteFrameCache->getSpriteFrameByName("ship01.png"));
        fly->addSpriteFrame(spriteFrameCache->getSpriteFrameByName("ship02.png"));
        fly->setDelayPerUnit(0.1);
        fly->setRestoreOriginalFrame(true);
        animationCache->addAnimation(fly, "FLY");


        auto explosion = cocos2d::Animation::create();
        explosion->addSpriteFrame(spriteFrameCache->getSpriteFrameByName("explode1.png"));
        explosion->addSpriteFrame(spriteFrameCache->getSpriteFrameByName("explode2.png"));
        explosion->addSpriteFrame(spriteFrameCache->getSpriteFrameByName("explode3.png"));

        for (int i = 1; i <= 35; i++)
        {
            std::string name;
            if (i < 10)
            {
                name = std::string("explosion_0") + ToString(i) + ".png";
            }
            else
            {
                name = std::string("explosion_") + ToString(i) + ".png";
            }
            explosion->addSpriteFrame(spriteFrameCache->getSpriteFrameByName(name));
        }

        explosion->setDelayPerUnit(0.04);
        explosion->setRestoreOriginalFrame(true);
        animationCache->addAnimation(explosion, "EXPLOSION");
        
        return true;
    }

}

#endif /* Resource_h */
