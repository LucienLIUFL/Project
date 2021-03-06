# 飞行轨迹设计

飞行轨迹指的是敌方战机的运动路径,在游戏中,我们不仅仅只设计从上到下固定的游戏轨迹,丰富的地方战机移动路径可以大大丰富游戏的趣味性.为了实现敌方战机与路径的分别控制,游戏将路径的实现与敌机创建进行分离,使用一个单独的模块对轨迹进行管理.

轨迹模块共实现了六种轨迹,分别是:

1. 从屏幕的右上角开始,进入场景后进行横向移动,在移动的图中发射子弹.然后迅速俯冲向屏幕底部中点.以及其镜像轨迹,轨迹展示如下:
2. 从屏幕的右上角开始,俯冲向屏幕底部,然后回退到上部进行横向移动,移动的过程中发射子弹,最后垂直俯冲.以及其镜像轨迹,轨迹展示如下:
3. 从屏幕顶端中点开始移动,垂直移动到中线上部,然后开始向左方横移,移动到屏幕边缘后反向右方横移,到达右屏幕边缘后再次反向向中线移动,到达中线后俯冲.在这个横向移动过程中,不断发射子弹.轨迹展示如下:
4. 从屏幕底端右部开始,迅速移动到屏幕左上角,然后横移到屏幕右上角,然后俯冲到屏幕左下角,横移过程中不断发射子弹.这一个轨迹与普通轨迹不同,不是传统的从上部开始,移动范围广,速度极快,玩家往往反映不够及时,无法马上躲避,是一个难度很大的轨迹.轨迹展示如下:

6种轨迹每一个都是由工厂方法进行创建,返回一个轨迹对象.但是调用六种方法的设计并不灵活, C++也没有函数反射的设计,因此我使用一个总的工厂方法,利用一个 Flag 来控制调用哪一个.同时,传入一个敌机对象指针,使得可以调用对象的射击方法并设置对象的位置.伪代码实现如下:


```
assert((flag <= 5 && flag >= 0));
switch (flag)
{
    case 0 :
        return CreateA();
    case 1 :
        return CreateB();
    case 2 :
        return CreateC();
    case 3 :
        return CreateD();
    case 4 :
        return CreateE();
    case 5 :
        return CreateF();
}
```

[所有的轨迹图]