## 2.5 处理类型

这里主要介绍了 typedef（type alias）、using（alias declaration）、auto 和 decltype。主要解决的矛盾是对于某个计算得到的值，获取其类型的麻烦。

核心矛盾是 C++ 的类型太复杂。从前的解决方案是使用 typedef（在新标准中也可用 using），给类型取更可读的名字：

```c++
typedef T type_of_get_value;
using type_of_get_value = T;
```

但是显然没完全解决问题。

### auto

auto 关键字自动推导某个值的类型。依照对 C++ 的认识，显然这个过程发生在编译期。

```c++
auto value = get_value();
```

无非是编译期做了某些你本来要做的工作。

值得注意的是，如果已知一个类型 E，那么 const E 便是这种类型进行不可修改的修饰后得到的类型；E& 是这种类型的引用类型。但是反过来卻不容易。

所以 auto 的设计中，如果 get_value() 是个 const，推导中会把 const 去掉；如果是个引用，也会把引用去掉。以便满足所有的获取类型的需求。

```c++
const int ci = 10;
auto a1 = ci; // auto 代表 int 而不是 const int

int& ri = ci;
auto a2 = ri; // auto 代表 int 而不是 int&

// 如果想得到 const 版本或者引用版本，使用显式声明即可
const auto a3 = ci;
auto& a4 = ri;
// auto 的意义还是不变的
```

### decltype

decltype(expression) 在编译期根据 expression 的类型替换为某个类型。

```c++
decltype(get_value()) u = get_value();
```

注意，这个过程发生在编译期。这意味着 decltype() 中的表达式不是真的被取值（如果这是一个函数，那么不是真的被执行）。所以上面的代码里 get_value() 只被执行了一次。

**TODO@张静织**

然而对于这个推导的值什么时候是引用、什么时候是值类型，老夫没看懂。咸鱼交给你了。
