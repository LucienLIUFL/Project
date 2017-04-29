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

namespace Resource {
    const std::string BACK_PLANE = "ImageRaw/textureTransparentPack.plist";
    const std::string BULLET_HIT_EXPLODE= "ImageRaw/textureOpaquePack.plist";
    const std::string EXPLOSION = "ImageRaw/explosion.plist";
    const std::string BACK_BUILD = "ImageRaw/b01.plist";
    const std::string FLARE = "ImageRaw/flare.jpg";

    const std::string BACK_GROUND_PATH = "ImageRaw/textureTransparentPack.plist";
    const std::string BACK_BUILDS_PATH = "ImageRaw/b01.plist";

    inline bool Load() {
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

        for (int i = 1; i <= 35; i++) {
            std::string name;
            if (i < 10) {
                name = std::string("explosion_0") + std::to_string(i) + ".png";
            } else {
                name = std::string("explosion_") + std::to_string(i) + ".png";
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
