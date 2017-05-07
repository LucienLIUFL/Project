# 欢迎场景的设计与实现

欢迎场景是进入游戏之后玩家看到的第一个场景,其采用单层设计,即一个场景中只有一个层,层创建采用经典的两段式,并将层的实例化代码写入创建场景的静态方法当中.

欢迎场景实现的功能如下所示:
1. 加载资源.
2. 渲染游戏 Logo,静态背景.
3. 渲染开始开始按钮并添加场景切换事件.
4. 渲染作者信息.
5. 渲染装饰用的飞机精灵,并根据帧数调用射击方法.

其中加载资源在资源管理部分有详细的介绍,在这里不再赘述.而渲染游戏 Logo,背景,信息等比较简单,在这里也不做过多描述.下面着重介绍一下开始事件的设计与飞机精灵的添加.

## 开始按钮的设计

开始按钮的监听为当按钮被按下,则创建一个延时事件,和一个场景切换事件,在延时时间的同时,创建一个闪光特效.
闪光特效的实现在特效一节介绍,这里不做进一步描述,延时事件保证了闪光特效完全播放完毕后才进入场景切换.两个事件由当前层顺序执行.

## 飞机精灵的添加

飞机精灵是模型中玩家战机的实例化,但是在本层中并不添加物理刚体,仅做装饰用.在本层的 init 方法中进行实例化,并添加无限循环的左右移动动作.在场景的更新函数中,每十帧调用一次射击方法,用于创建自动销毁的子弹精灵,这个过程在模型设计的部分进行详细的介绍.

## 欢迎场景的效果展示