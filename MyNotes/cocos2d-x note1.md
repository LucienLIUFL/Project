# Cocos2d-x Note 1


## Cocos2d console command

创建：

`cocos new [NAME] -l [LANGUAGE] -d [PATH]`

编译：

`cocos compile -p [PLATFORM]`

运行：

`cocos run -p [PLATFORM]`

## 编译到 Android 平台 


## 总结

完成了项目源码的编写，将环境搭建好，并且将项目打包到Android平台

总算是将这一个小游戏完成了，勉强算是一个完整的游戏：有背景音乐、有游戏场景、也可正常的使用。
但是在开发过程中仍然是遭遇了许多问题。

1. Cocos2d-x 引擎的API不熟悉，许多问题也许有更好的解决办法，比如进度条动画的设计，以及碰撞检测，精灵对象的移除等。
2. 代码的耦合度较高，渲染、逻辑以及扩展混杂在一起，降低了可维护性和可读性，非常混乱。
3. 编码能力欠火候，突出的暴露了自己在设计模式上的不足，不能灵活运用。
4. 一个Scene仅有一个Layer的问题，这样设计很不合理。



