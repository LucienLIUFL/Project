# 背景层设计

背景层的设计分为
1. 背景的自动滚动
2. 添加堡垒精灵元素, 执行移动效果并自动移除

## 背景的自动滚动
在我们的飞机游戏中, 为了实现飞机飞行的效果, 要求我们的背景层可以向下滚动,
已达到玩家认为飞机正在飞行的错觉.

我们采用两张背景图精灵元素交替执行下移的方法来实现背景层的滚动效果,
具体的方法是创建两个上下并列的背景图, 第一张在上, 第二张在下, 也就是说, 
当玩家看到第一张图片的时候, 第二张图片恰好处于第一张图片看不到的地方,
然后执行第一张图片下移, 第二张图片跟随下移, 直至第一张图片完全移出屏幕,
即第二张图片完全移入屏幕, 此时将第一张图片的位置重设到第二张图片的上部,
并重新执行这个过程.
通过这样的方式, 在视觉上, 玩家无法看到屏幕外的情况, 因此可以产生背景图滚动的效果.

以下是实现此效果的伪代码:
```
firstImage.Pos.Y--;
if firstImage.Pos OutOf visibleSize:
    firstImage.Pos = Up to secondImage.Pos;
secondImage.Pos.Y--;
if secondImage.Pos OutOf visibleSize:
    secondImage.Pos = Up to firstImage.Pos;
```
流程图

效果图

使用的数据结构
两张背景精灵元素的数组, 在当前背景层实例化时创建;

## 堡垒元素的添加

为了体现雷霆战机游戏的科技感, 游戏设计了不同的堡垒, 作为背景的添加元素.
堡垒的纹理图片一共有四种, 如下所示
[图片]

堡垒精灵加入从上到下的移动动作, 从屏幕外的上部开始, 到从下部完全移出屏幕结束, 
然后将此精灵从本层删除. 精灵下落为垂直下落, 起始的横坐标为随机. 背景层设置一个堡垒的标志位, 
取值为0 - 3, 表示不同的堡垒精灵, 在添加的过程中, 每添加一次, 将标志位加一, 到达上限后, 归零.
添加堡垒元素的时机为, 两个背景图进行坐标重设的时候.

堡垒精灵添加之后, 需要在执行完毕动作后进行自动移除, 否则会造成精灵元素在下部不断积累, 
以至于大量的内存资源不断被浪费. 因此, 我们需要自动检测完成动作的堡垒元素, 并将其从本层移除.

添加堡垒后, 伪代码被更新为 

```
firstImage.Pos.Y--;
if firstImage.Pos OutOf visibleSize:
    firstImage.Pos = Up to secondImage.Pos;
    Add BuildingWithMoveAction(BuildingFlag, RandomPos);
secondImage.Pos.Y--;
if secondImage.Pos OutOf visibleSize:
    secondImage.Pos = Up to firstImage.Pos;
    Add BuildingWithMoveAction(BuildingFlag, RandomPos);

CheckAndRemove(All_Buildings); 
```

流程图

使用的数据结构
四个创建好的精灵元素. 在当前背景层实例化时创建.

## 背景层的方法重写

我们的背景层继承自 cocos2d-x 引擎的 Layer 元素, 我们重写其 init 方法与 update 方法.
init 方法是背景层的初始化方法, 在背景层初次创建时会被调用, 
我们将背景层所需要的各种数据结构的实例化过程放在此方法中.

update 方法是背景层的更新方法, 这个方法用于在每一帧重新渲染精灵并作出一些修改, 
调用的次数与当前的帧率相关. 我们将以上的伪代码的实现放在这个方法里.

## 背景层的内存管理方式

背景层采取两段式创建, 将类的实例化与初始化分离, 采用工厂模式, 并在初始化之后调用 Ref 类的 autorelease 方法, 将层对象自动托管到全局的内存池. 