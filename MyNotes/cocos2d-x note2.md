#帧动画

## API Reference

1. SpriteFrame
2. SpriteFrameCache

## 创建方法

## 学习笔记

1. 动画创建器

### Question 0x0

```
cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroComobo.plist");
```

Raising Error:

```
cocos2d: fullPathForFilename: No file found at heroComobo.plist. Possible missing file.
cocos2d: SpriteFrameCache: can not find heroComobo.plist
```

Solve: Add plist path in Xcode;

### Question 0x1

```
cocos2d: QuadCommand: resizing index size from [-1] to [2560]
```

Solve: director->setDisplayStats(true) --> false;

2. virtual 后加override关键字;