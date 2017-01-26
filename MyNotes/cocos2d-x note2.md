##帧动画

1. SpriteFrame
2. SpriteFrameCache

### 创建方法

动画创建器

`cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("heroComobo.plist");`

Raising Error:

```
cocos2d: fullPathForFilename: No file found at heroComobo.plist. Possible missing file.
cocos2d: SpriteFrameCache: can not find heroComobo.plist
cocos2d: QuadCommand: resizing index size from [-1] to [2560]
```