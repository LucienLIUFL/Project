#Frame Animation

## API Reference

1. SpriteFrame
2. SpriteFrameCache

## Create Node

```
    static cocos2d::Animation * createAnimation(const std::string & filename, int num, double delay) {
        cocos2d::SpriteFrame * spriteFrame;
        cocos2d::Animation * animation = cocos2d::Animation::create();
        cocos2d::SpriteFrameCache * spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();

        // Fetch sprite frames form sprite frame cache and append them to animation
        for (int i = 0; i < num; i++) {
            spriteFrame = spriteFrameCache->getSpriteFrameByName(filename + toString(i + 1) + ".png");
            animation->addSpriteFrame(spriteFrame);
        }

        // Set the Animation Interval
        animation->setDelayPerUnit(static_cast<float>(delay));

        // Set ture to make animation back to first frame after done
        animation->setRestoreOriginalFrame(true);
        return animation;
    }

    static void debug(cocos2d::Layer * layer) {
        // 1st Step: Read plist file and add it to spirteFrameCache
        cocos2d::SpriteFrameCache * spriteFrameCache = cocos2d::SpriteFrameCache::getInstance();
        spriteFrameCache->addSpriteFramesWithFile("plist/hero.plist");

        // 2nd Step: Create Animation and use it to create Animate(inherit form Action)
        cocos2d::Animation * animation = createAnimation("run", 12, 0.05);
        cocos2d::Animate * animate = cocos2d::Animate::create(animation);

        // 3rd Step: use the first frame of animation to create a sprite
        cocos2d::SpriteFrame * spriteFrame = spriteFrameCache->getSpriteFrameByName("run1.png");
        cocos2d::Sprite * sprite = cocos2d::Sprite::createWithSpriteFrame(spriteFrame);
        cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        sprite->setPosition(cocos2d::Vec2(visibleSize.width/2.0f, visibleSize.height/2.0f));
        sprite->setScale(0.3f);

        // 4th Step: run the animate with sprite
        cocos2d::RepeatForever * repeatForever = cocos2d::RepeatForever::create(animate);
        sprite->runAction(repeatForever);

        layer->addChild(sprite);
    }
```

## Debug Note

1.  Question 0x0

```
    cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroComobo.plist");
```

Raising Error:

```
    cocos2d: fullPathForFilename: No file found at heroComobo.plist. Possible missing file.
    cocos2d: SpriteFrameCache: can not find heroComobo.plist
```

Solve: Add plist path in Xcode;

2. Question 0x1

```
    cocos2d: QuadCommand: resizing index size from [-1] to [2560]
```

Solve: director->setDisplayStats(true) --> false;

2. using _override_ keyword in overrided virtual function declaring;