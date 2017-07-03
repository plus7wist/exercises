## 4.2 算术运算符

`m % (-n)` 与 `m % n` 相等；`(-m) % n` 与 `-(m % n)` 相等。

这种计算机语言上的表达与数学表达有所出入：`-12 % 5` 也即 `-(12 % 5)` 结果是 -2；但是数学上 -12 膜 5 应是 3。

如果要用到数学式的膜运算：

```c++
using int = itype;

itype math_mod(itype& a, itype m)
{
    a %= m;
    if (a < 0) {
        a += m;
    }
    return a;
}
```

同理，很多时候认为对整数类型 `a / b` 即等于 a/b 的下取整但这只有在正数情况下适用。

```c++
itype ifloor(itype a, itype b)
{   return (a - math_mod(a, b)) / b;    }

itype iceil(itype a, itype b)
{   return ifloor(a + b - 1, b);    }
```

## 4.3 逻辑和关系运算符

```c++
for (const auto &s : text)   // text 为文本
```
`text`的元素是 `std::string` 对象，可能非常大，将 `s` 声明为引用类型可以避免对元素的拷贝。

## 4.6 递增和递减运算符

建议使用 `++i`，除非必须，不建议使用 `i++`：`i++` 需要将原始值存储下来以便于返回这个未修改的内容。如果不需要修改前的值，那么 `i++` 操作是一种浪费。

如果想在一条符合表达式中即将变量 +1/-1 又能使用它原来的值，这时使用 `i++`：

```c++
cout << *iter++ << endl    //简洁是一种美德
```

## 4.8 位运算符

位运算符关于符号位如何处理**没有明确的规定**，所以强烈建议仅将位运算符用于处理**无符号类型**。

## 4.11.3 显示转换 TODO@小鱼儿

`static_cast const_cast` 无能为力orzzzzzz
