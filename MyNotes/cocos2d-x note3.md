#Event Listener

1. Get Dispatcher
```
 cocos2d::Director * director = cocos2d::Director::getInstance();
 cocos2d::EventDispatcher * eventDispatcher = director->getEventDispatcher();
```

2. Create Event Object

```
cocos2d::EventListenerTouchOneByOne * singleTouch = cocos2d::EventListenerTouchOneByOne::create();
```

3. Override the callback function
```
typedef std::function<bool(Touch*, Event*)> ccTouchBeganCallback;
typedef std::function<void(Touch*, Event*)> ccTouchCallback;

ccTouchBeganCallback onTouchBegan;
ccTouchCallback onTouchMoved;
ccTouchCallback onTouchEnded;
ccTouchCallback onTouchCancelled;

singleTouch->onTouchBegan = std::bind(onTouchBegan, std::placeholders::_1, std::placeholders::_2);
singleTouch->onTouchMoved = std::bind(onTouchCallback, std::placeholders::_1, std::placeholders::_2);

```

4. Add Event Listener to Dispatcher

```
eventDispatcher->addEventListenerWithSceneGraphPriority(singleTouch, target);
```