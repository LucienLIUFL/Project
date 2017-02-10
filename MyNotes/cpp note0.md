# explicit implicit关键字总结

## 隐式转换

《C++ Primer》中提到：

"可以用单个形参来调用的构造函数定义了从形参类型到该类类型的一个隐式转换."

注: "可以用单个形参进行调用"并不是指构造函数只能有一个形参, 而是它可以有多个形参, 但那些形参都是有默认实参的.

所谓隐式转换是从构造函数形参类型到该类类型的一个编译器的自动转换.

比如：
```
class Object {
public:
    Object(const std::string & name) : _name(name) {}
private:
    std::string _name;
};

class Book {
public:
    Book(const Object & object) : _object(object) {}

    std::string show() {
        return _object._name;
    }
private:
    Object _object;
};

Object object = std::string("Potter"); // 可以正常编译, std::string被隐式转换为Object类型;
Book Maples(std::string("Maples")); // 可以正常编译, std::string被隐式转换为Object类型;
```

## explicit关键字

隐式类类型转换还是会带来风险的, 正如上面标记, 隐式转换得到类的临时变量, 完成操作后就消失了, 我们构造了一个完成测试后被丢弃的对象.

我们可以通过explicit声明来抑制这种转换:

```
explicit Object(const std::string & name) : _name(name) {}

// 再次编译, 输出

Main.cpp:26:12: error: no viable conversion from 'std::string' (aka 'basic_string<char, char_traits<char>, allocator<char> >') to
      'Object'
    Object object = std::string("Potter");
           ^        ~~~~~~~~~~~~~~~~~~~~~
      ^
Main.cpp:28:10: error: no matching constructor for initialization of 'Book'
```
## 总结一下：

1. 可以使用一个实参进行调用, 不是指构造函数只能有一个形参.
2. 隐式类类型转换容易引起错误, 除非你有明确理由使用隐式类类型转换, 否则, 将可以用一个实参进行调用的构造函数都声明为explicit. 
3. explicit只能用于类内部构造函数的声明, 它虽然能避免隐式类型转换带来的问题, 但需要用户能够显式创建临时对象(对用户提出了要求).